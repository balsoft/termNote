{ pkgs ? import <nixpkgs> {} }:
let
    termNote = pkgs.callPackage ./termNote.nix;
    nix-bundle-src = builtins.fetchGit
    {
       url = "https://github.com/matthewbauer/nix-bundle";
       rev = "113d8c6b426b0932a64c58c21cd065baad4c2314";
    };
    nix-bundle = (import ("${nix-bundle-src}/appimage-top.nix") {}) // (import "${nix-bundle-src}/default.nix" {});
    AppImages =
    {
        termNote = nix-bundle.appimage
        (nix-bundle.appdir
        {
            name = "termNote";
            target = termNote { desktop = true; notify = false; };
        });
        noted = nix-bundle.appimage
        (nix-bundle.appdir
        {
            name = "noted";
            target = termNote { desktop = true; desktopTarget = "noted"; };
        });
    };
    bundles =
    {
        termNote = nix-bundle.nix-bootstrap
        {
            extraTargets = [];
            target = termNote { notify = false; };
            run = "/bin/termNote";
            nixUserChrootFlags = "-m /root:root";
        };
        noted = nix-bundle.nix-bootstrap
        {
            extraTargets = [];
            target = termNote {};
            run = "/bin/noted";
            nixUserChrootFlags = "-m /root:root";
        };
    };
in
(termNote { test = true; }) // { inherit AppImages bundles; }

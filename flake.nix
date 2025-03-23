{
  description = "Tree-sitter grammar for parsing LispBM code";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
    treefmt-nix.url = "github:numtide/treefmt-nix";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
      treefmt-nix,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
        treefmtEval = treefmt-nix.lib.evalModule pkgs ./treefmt.nix;
      in
      {
        # For `nix develop`
        devShells.default = pkgs.mkShell {
          buildInputs = [
            pkgs.tree-sitter
            pkgs.nodejs_23
            pkgs.python312
          ];
        };

        # For `nix fmt`
        formatter = treefmtEval.config.build.wrapper;

        # For `nix flake check`
        checks = {
          formatting = treefmtEval.config.build.check self;
        };
      }
    );
}

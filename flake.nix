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
          # Checks that the parser source is in sync with grammar.js
          parserGenerated =
            pkgs.runCommand "parser-generated-check"
              {
                nativeBuildInputs = [
                  pkgs.git
                  pkgs.tree-sitter
                  pkgs.nodejs_23
                ];
              }
              ''
                # Create source directory.
                set -e
                cp -r ${self} source/
                chmod -R a+w source/
                cd source/

                tree-sitter generate

                # Check that nothing changed
                if ! diff --color=always --recursive ${self} .; then
                  echo "Generated parser not up to date with 'parser.js'. Please run the following:"
                  echo "  tree-sitter generate"
                  exit 1
                fi

                touch $out
              '';
          # Checks that `tree-sitter test` passes
          parserTests =
            pkgs.runCommandCC "parser-tests-check"
              {
                nativeBuildInputs = [ pkgs.tree-sitter ];
              }
              ''
                # Create source directory.
                set -e
                cp -r ${self} source/
                cd source/
                export HOME=$TMPDIR

                tree-sitter test

                touch $out
              '';
        };
      }
    );
}

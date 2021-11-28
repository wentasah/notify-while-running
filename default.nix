{ pkgs ? import <nixpkgs> {}}:
with pkgs; stdenv.mkDerivation {
  name = "notify-while-running";
  src = nix-gitignore.gitignoreSource [] ./.;
  nativeBuildInputs = [ pkg-config ];
  buildInputs = [ libnotify ];
  makeFlags = [ "PREFIX=${placeholder "out"}" ];
}

{ pkgs ? import <nixpkgs> {} }:

pkgs.stdenv.mkDerivation {
  pname = "enigma";
  version = "1.1";

  src = ./Enigma-main;

  nativeBuildInputs = [ pkgs.cmake ];
  buildInputs = [ pkgs.openssl ];

  # El CMakeLists intenta instalar rotors_BIN al $HOME del build,
  # lo cual falla en el sandbox de Nix. Lo sobreescribimos:
  installPhase = ''
    cmake --install . --prefix $out
    mkdir -p $out/share/enigma
    cp $src/bin/rotors_BIN $out/share/enigma/rotors_BIN
  '';
}

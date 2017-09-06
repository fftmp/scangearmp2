# This repo contain:
1. scangearmp2 utlity with it's binary blobs from canon
1. SANE backend canon_pixma from [Ordissimo](https://github.com/Ordissimo/scangearmp2). This backend also uses blobs from canon.
1. Some refactoring and improvements from me:
    - PKGBUILD for archlinux
    - russian translation
    - can compile with -Wall -Wextra
    - remove duplicate code
    - change autotools to cmake
# INSTALL
    - makepkg for archlinux or cmake && make install for others
    - add canon_pixma backend to sane backends list: echo "canon_pixma" >> /etc/sane.d/dll.conf
# Known bugs and restrictions:
1. can't change resolution, only 300dpi works. Was tested on TS9040. May be this is restriction from canon blobs.
1. need 64bit OS and sufficiently modern gcc (must support c11) and cmake (ver>=3.4) for build. This is restriction only of this fork.
1. there is no rpm or deb packages. Is someone will need it, I will add.

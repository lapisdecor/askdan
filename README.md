# askdan
Get Dan's recomendation for wich package type to use.

Usage:
./askdan application_name

Currently supports .deb, snap, flatpak and appimage.
You can add your own recommendation to the csv file.


*How to add*
csv fields: app_name, deb_exists, snap_exists, flatpak_exists, appimage_exists, recommendation

example csv line:
bzoing,0,1,0,0,1

recommendation codes:
0 - deb,
1 - snap,
2 - flatpak,
3 - appimage.

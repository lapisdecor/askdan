# askdan
Get Dan's recomendation for wich package type to use.

Install:
sudo snap install askdan --edge

Usage:
askdan application_name

Currently supports .deb, snap, flatpak and appimage.
You can add your own recommendation to the csv file.


*How to add apps to the csv*
csv fields: app_name, deb_exists, snap_exists, flatpak_exists, appimage_exists, recommendation

example csv line:
bzoing,0,1,0,0,1

1 means package is available
0 means package is not available

recommendation codes:
0 - deb,
1 - snap,
2 - flatpak,
3 - appimage.

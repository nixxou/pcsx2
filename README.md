# PCSX2 LightGun Edition

A custom build of PCSX2 made for LightGun Games

Only for guncon2 games, It will not solve the issue for Silent Scope.

Priorize US versions of games, EU will work, but some will have less features (recoil), miss some interesting patch...

GunCon must be configured in joystick mode using relative aiming.


Game Specific notes :

For 2 player Vampire Night, i had issue with calibrating 2nd gun, so you need to boot with gun 2 off, and activate it once in game.

For endgame, remember that gun2 = player 1 and gun1 = player2

For RE Gun Survivor 2, you have to bypass the qualibration screen, don't calibrate the gun.


ChangeLog :
- MameHooker and Direct Gun4IR recoil support
- Aim Fix for few games (Resident Evil Survivor 2, Starsky & Hutch (E))
- 2 players Aim fix for Time Crisis 2 and Time Crisis 3
- Build in cheats and configuration to fix some issue, remove some gunflash...
- Some extra stuff like per game reshade profile, autoload savestate 10 on start, reduce the pause menu size to fill in 4:3 if it's the display mode...



About the per-game reshade fix.

You need to have a default profile nammed DefaultReshadePreset (and so, a DefaultReshadePreset.ini in your pcsx folder).

Game specific profile must be nammed with the game serial, like SCES-50300.ini

Can be use to apply per game bezel or use certain effect on a game basis, like for exemple, i use EyeAdaption shader to reduce the gun flash of game that do not have a patch to remove it.
(https://github.com/brussell1/Shaders/blob/master/Shaders/EyeAdaption.fx)


Other stuff related to pcsx2 : 

I've made a no-smoke patch for Time Crisis 2 if you want, i do not include it by default, because the smoke is not a bug, so it's up to personal preference.
https://github.com/nixxou/pcsx2/releases/download/V1.0/optional_NOSMOKE-Patch-TimeCrisis2.zip


Don't forget there is HD texture pack for some of the games : 

Resident Evil Dead Aim : https://gbatemp.net/threads/resident-evil-dead-aim-hd-textures.649199/

Vampire Night : https://gbatemp.net/threads/vampire-night-hd-texture-pack.643864/

Time Crisis Crisis Zone : https://gbatemp.net/threads/time-crisis-crisis-zone-hd-texture-pack.643871/

Time Crisis 2 : https://gbatemp.net/threads/my-ps2-packs.621422/

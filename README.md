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

How to use the Recoil : 

Two options : 
- Using Mamehooker, the option to enable it is a checkbox in Options, Interface
- Using direct GunCon Com control. You can find the option to set the right com port in the advanced option of the guncon device.

List of games with recoil support : 
- SLES-50930 : Dino Stalker (E, English)
- SLES-51095 : Dino Stalker (E, French)
- SLUS-20485 : Dino Stalker (USA)
- SLUS-20389 : EndGame (US)
- SLPM-65139 : Gun Survivor 3: Dino Crisis (J)
- SLES-52620 : Guncom 2 (E)
- SLES-51289 : Gunfighter 2 - Jesse James (E)
- SLPS-25165 : Gunvari Collection (J) (480i) : Only for time crisis
- SLUS-20492 : Ninja Assault (U)
- SLES-50650 : Resident Evil Survivor 2 (E)
- SLUS-20669 : Resident Evil Dead Aim (US)
- SLES-51617 : Starsky & Hutch (E)
- SLUS-20619 : Starsky & Hutch (U)
- SCES-50300 : Time Crisis 2 (EU)
- SLUS-20219 : Time Crisis 2 (US)
- SCES-51844 : Time Crisis 3 (EU)
- SLUS-20645 : Time Crisis 3 (US)
- SLUS-20927 : Time Crisis Crisis Zone (US)
- SLUS-20221 : Vampire Night (U)
- SLES-51229 : Virtua Cop Elite Edition

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



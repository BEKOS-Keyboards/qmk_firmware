# Muse

![Atomics](imgur.com image replace me!)

*A fully open source "108" key hotswap keyboard with full RGB, macro/media keys, encoder with switch (for mute/unmute), EEPROM, and full VIA support*

* Keyboard Maintainer: [BEKOS](https://github.com/BOSS-Keyboards)
* Hardware Supported: Bekos Atomics Modular Hotswap PCB
* Hardware Availability: Currently in pre-production at this time

Make example for this keyboard (after setting up your build environment):

    make bekos/atomics:default

Flashing example for this keyboard:

    make bekos/atomics:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Muse Hardware Information

    /* Column pin configuration
    * col: 0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21
    * pin: A15  A10  A9   A8   C9   C8   C7   C6   B15  B14  B13  B12  B11  B10  B2   C5   C4   C3   A7   A6   A5   A4
    */
     
    /* Row pin configuration
    * row: 0    1    2    3    4    5
    * pin: B5   C1   D2   C12  C11  C10
    */
	

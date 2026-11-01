ENTRY(entry)

SECTIONS
{
    .image 0x01018000 :
    {
        KEEP(*(.blob.01018000))
        KEEP(*(.blob.01018004))
        KEEP(*(.blob.0101800a))
        KEEP(*(.blob.01018010))
        KEEP(*(.blob.01018016))
        KEEP(*(.blob.0101801c))
        KEEP(*(.blob.01018020))
        KEEP(*(.blob.01018024))
        KEEP(*(.blob.01018028))
        KEEP(*(.blob.0101802c))
        KEEP(*(.blob.01018030))
        KEEP(*(.blob.01018034))
        KEEP(*(.blob.01018038))
        KEEP(*(.blob.0101803c))
        KEEP(*(.blob.01018040))
        KEEP(*(.blob.01018044))
        KEEP(*(.blob.01018048))
        KEEP(*(.blob.0101804c))
        KEEP(*(.blob.01018050))
        KEEP(*(.blob.01018054))
        KEEP(*(.blob.01018058))
        KEEP(*(.blob.0101805c))
        KEEP(*(.blob.01018060))
        KEEP(*(.blob.01018064))
        KEEP(*(.blob.01018068))
        KEEP(*(.blob.0101806c))
        KEEP(*(.blob.01018070))
        KEEP(*(.blob.01018074))
        KEEP(*(.blob.01018078))
        KEEP(*(.blob.0101807c))
        KEEP(*(.blob.01018080))
        KEEP(*(.blob.01018084))
        KEEP(*(.blob.01018088))
        KEEP(*(.blob.0101808c))
        KEEP(*(.blob.01018090))
        KEEP(*(.blob.01018094))
        KEEP(*(.blob.01018098))
        KEEP(*(.blob.010180aa))
        KEEP(*(.blob.010180b4))
        KEEP(*(.blob.010180c2))
        KEEP(*(.blob.010180ce))
        KEEP(*(.blob.010180d4))
        KEEP(*(.blob.010180e2))
        KEEP(*(.text.FUN_010180e4 .text.startup.FUN_010180e4))
        ASSERT(ABSOLUTE(.) == 0x010180e6, "FUN_010180e4 is not its original size");
        KEEP(*(.text.FUN_010180e6 .text.startup.FUN_010180e6))
        ASSERT(ABSOLUTE(.) == 0x010180e8, "FUN_010180e6 is not its original size");
        KEEP(*(.text.FUN_010180e8 .text.startup.FUN_010180e8))
        ASSERT(ABSOLUTE(.) == 0x010180ea, "FUN_010180e8 is not its original size");
        KEEP(*(.text.FUN_010180ea .text.startup.FUN_010180ea))
        ASSERT(ABSOLUTE(.) == 0x010180ec, "FUN_010180ea is not its original size");
        KEEP(*(.text.FUN_010180ec .text.startup.FUN_010180ec))
        ASSERT(ABSOLUTE(.) == 0x010180ee, "FUN_010180ec is not its original size");
        KEEP(*(.text.FUN_010180ee .text.startup.FUN_010180ee))
        ASSERT(ABSOLUTE(.) == 0x010180f0, "FUN_010180ee is not its original size");
        KEEP(*(.text.FUN_010180f0 .text.startup.FUN_010180f0))
        ASSERT(ABSOLUTE(.) == 0x010180f2, "FUN_010180f0 is not its original size");
        KEEP(*(.text.FUN_010180f2 .text.startup.FUN_010180f2))
        ASSERT(ABSOLUTE(.) == 0x010180f4, "FUN_010180f2 is not its original size");
        KEEP(*(.text.FUN_010180f4 .text.startup.FUN_010180f4))
        ASSERT(ABSOLUTE(.) == 0x010180f6, "FUN_010180f4 is not its original size");
        KEEP(*(.text.FUN_010180f6 .text.startup.FUN_010180f6))
        ASSERT(ABSOLUTE(.) == 0x010180f8, "FUN_010180f6 is not its original size");
        KEEP(*(.text.FUN_010180f8 .text.startup.FUN_010180f8))
        ASSERT(ABSOLUTE(.) == 0x010180fa, "FUN_010180f8 is not its original size");
        KEEP(*(.text.FUN_010180fa .text.startup.FUN_010180fa))
        ASSERT(ABSOLUTE(.) == 0x010180fc, "FUN_010180fa is not its original size");
        KEEP(*(.blob.010180fc))
        KEEP(*(.blob.01018200))
        KEEP(*(.blob.01018208))
        KEEP(*(.blob.01018214))
        KEEP(*(.blob.01018240))
        KEEP(*(.blob.01018268))
        KEEP(*(.blob.0101828c))
        KEEP(*(.blob.0101829a))
        KEEP(*(.blob.0101829e))
        KEEP(*(.blob.010182b0))
        KEEP(*(.blob.010182ca))
        KEEP(*(.blob.010182dc))
        KEEP(*(.blob.010182f0))
        KEEP(*(.blob.01018302))
        KEEP(*(.blob.01018364))
        KEEP(*(.blob.01018388))
        KEEP(*(.blob.010183a8))
        KEEP(*(.blob.010183ca))
        KEEP(*(.blob.01018420))
        KEEP(*(.blob.01018544))
        KEEP(*(.blob.01018580))
        KEEP(*(.blob.010185c0))
        KEEP(*(.blob.0101879c))
        KEEP(*(.blob.0101886c))
        KEEP(*(.text.FUN_010188c8 .text.startup.FUN_010188c8))
        ASSERT(ABSOLUTE(.) == 0x010188d2, "FUN_010188c8 is not its original size");
        KEEP(*(.blob.010188d2))
        KEEP(*(.blob.01018940))
        KEEP(*(.blob.0101898c))
        KEEP(*(.blob.010189f0))
        KEEP(*(.blob.01018a54))
        KEEP(*(.blob.01018a76))
        KEEP(*(.blob.01018aa4))
        KEEP(*(.blob.01018ac8))
        KEEP(*(.blob.01018b1c))
        KEEP(*(.blob.01018b70))
        KEEP(*(.blob.01018bc8))
        KEEP(*(.blob.01018c1c))
        KEEP(*(.blob.01018c70))
        KEEP(*(.blob.01018d2c))
        KEEP(*(.blob.01018d8c))
        KEEP(*(.blob.01018e0c))
        KEEP(*(.blob.01018eda))
        KEEP(*(.blob.01018f14))
        KEEP(*(.blob.01018f16))
        KEEP(*(.blob.01018f18))
        KEEP(*(.blob.01018f30))
        KEEP(*(.blob.01018f40))
        KEEP(*(.blob.01018f42))
        KEEP(*(.blob.01018f44))
        KEEP(*(.blob.01018f46))
        KEEP(*(.blob.01018f48))
        KEEP(*(.blob.01018f4a))
        KEEP(*(.blob.01018f4c))
        KEEP(*(.blob.01018f4e))
        KEEP(*(.blob.01018f82))
        KEEP(*(.blob.01018f84))
        KEEP(*(.blob.01018f86))
        KEEP(*(.blob.01018f88))
        KEEP(*(.blob.01018f8a))
        KEEP(*(.blob.01018f92))
        KEEP(*(.blob.01018fd6))
        KEEP(*(.blob.01019014))
        KEEP(*(.blob.01019016))
        KEEP(*(.blob.01019018))
        KEEP(*(.blob.0101901a))
        KEEP(*(.blob.0101901c))
        KEEP(*(.blob.0101901e))
        KEEP(*(.blob.01019020))
        KEEP(*(.blob.01019022))
        KEEP(*(.blob.01019024))
        KEEP(*(.blob.01019026))
        KEEP(*(.blob.01019028))
        KEEP(*(.blob.0101905e))
        KEEP(*(.blob.01019060))
        KEEP(*(.blob.01019062))
        KEEP(*(.blob.010190ca))
        KEEP(*(.blob.0101918e))
        KEEP(*(.blob.010191a6))
        KEEP(*(.blob.010191b4))
        KEEP(*(.blob.010191b6))
        KEEP(*(.blob.010191c4))
        KEEP(*(.blob.010191f4))
        KEEP(*(.blob.010191fc))
        KEEP(*(.blob.010191fe))
        KEEP(*(.blob.01019200))
        KEEP(*(.blob.01019202))
        KEEP(*(.blob.01019204))
        KEEP(*(.blob.01019206))
        KEEP(*(.blob.01019208))
        KEEP(*(.blob.0101920a))
        KEEP(*(.blob.0101920c))
        KEEP(*(.blob.0101920e))
        KEEP(*(.blob.01019210))
        KEEP(*(.blob.01019212))
        KEEP(*(.blob.01019214))
        KEEP(*(.blob.01019230))
        KEEP(*(.blob.01019232))
        KEEP(*(.blob.01019234))
        KEEP(*(.blob.01019236))
        KEEP(*(.blob.01019238))
        KEEP(*(.blob.0101923a))
        KEEP(*(.blob.01019260))
        KEEP(*(.blob.01019262))
        KEEP(*(.blob.01019264))
        KEEP(*(.blob.01019266))
        KEEP(*(.blob.01019268))
        KEEP(*(.blob.0101926a))
        KEEP(*(.blob.01019290))
        KEEP(*(.blob.010192b6))
        KEEP(*(.blob.010192b8))
        KEEP(*(.blob.010192ba))
        KEEP(*(.blob.010192bc))
        KEEP(*(.blob.010192be))
        KEEP(*(.blob.010192c0))
        KEEP(*(.blob.010192c2))
        KEEP(*(.blob.010192c4))
        KEEP(*(.blob.010192c6))
        KEEP(*(.blob.010192c8))
        KEEP(*(.blob.010192de))
        KEEP(*(.blob.010192f4))
        KEEP(*(.blob.0101930a))
        KEEP(*(.blob.01019320))
        KEEP(*(.blob.01019336))
        KEEP(*(.blob.0101934c))
        KEEP(*(.blob.01019362))
        KEEP(*(.blob.01019378))
        KEEP(*(.blob.010193a6))
        KEEP(*(.blob.010193bc))
        KEEP(*(.blob.010193e2))
        KEEP(*(.blob.010193f8))
        KEEP(*(.blob.0101940e))
        KEEP(*(.blob.01019424))
        KEEP(*(.blob.0101943a))
        KEEP(*(.blob.01019450))
        KEEP(*(.blob.01019466))
        KEEP(*(.blob.0101947c))
        KEEP(*(.blob.01019492))
        KEEP(*(.blob.010194a8))
        KEEP(*(.blob.010194be))
        KEEP(*(.blob.010194d4))
        KEEP(*(.blob.010194ea))
        KEEP(*(.blob.01019500))
        KEEP(*(.blob.01019516))
        KEEP(*(.blob.0101952c))
        KEEP(*(.blob.01019542))
        KEEP(*(.blob.01019558))
        KEEP(*(.blob.0101956e))
        KEEP(*(.blob.01019584))
        KEEP(*(.blob.0101959a))
        KEEP(*(.blob.010195b0))
        KEEP(*(.blob.010195c6))
        KEEP(*(.blob.010196c0))
        KEEP(*(.blob.010196d6))
        KEEP(*(.blob.010196ee))
        KEEP(*(.blob.01019704))
        KEEP(*(.blob.01019708))
        KEEP(*(.blob.0101970e))
        KEEP(*(.blob.01019718))
        KEEP(*(.blob.0101972e))
        KEEP(*(.blob.01019730))
        KEEP(*(.blob.01019732))
        KEEP(*(.blob.01019754))
        KEEP(*(.blob.0101976a))
        KEEP(*(.blob.0101976c))
        KEEP(*(.blob.0101976e))
        KEEP(*(.blob.01019790))
        KEEP(*(.blob.010197c2))
        KEEP(*(.blob.010197c4))
        KEEP(*(.blob.010197f6))
        KEEP(*(.blob.010197fe))
        KEEP(*(.blob.01019806))
        KEEP(*(.blob.0101986c))
        KEEP(*(.blob.010198bc))
        KEEP(*(.blob.010198e8))
        KEEP(*(.blob.0101991e))
        KEEP(*(.blob.01019938))
        KEEP(*(.blob.0101995a))
        KEEP(*(.blob.01019968))
        KEEP(*(.blob.0101996a))
        KEEP(*(.blob.01019978))
        KEEP(*(.blob.010199b4))
        KEEP(*(.blob.01019a14))
        KEEP(*(.blob.01019a48))
        KEEP(*(.blob.01019a72))
        KEEP(*(.blob.01019a74))
        KEEP(*(.blob.01019a76))
        KEEP(*(.blob.01019a78))
        KEEP(*(.blob.01019a7a))
        KEEP(*(.blob.01019a7c))
        KEEP(*(.blob.01019a7e))
        KEEP(*(.blob.01019a80))
        KEEP(*(.blob.01019a82))
        KEEP(*(.blob.01019a84))
        KEEP(*(.blob.01019a86))
        KEEP(*(.blob.01019a88))
        KEEP(*(.blob.01019a8a))
        KEEP(*(.blob.01019ad2))
        KEEP(*(.blob.01019aea))
        KEEP(*(.blob.01019b2c))
        KEEP(*(.blob.01019b40))
        KEEP(*(.blob.01019b60))
        KEEP(*(.blob.01019b9e))
        KEEP(*(.blob.01019bbe))
        KEEP(*(.blob.01019bde))
        KEEP(*(.blob.01019be0))
        KEEP(*(.blob.01019bfa))
        KEEP(*(.blob.01019c3c))
        KEEP(*(.blob.01019c3e))
        KEEP(*(.blob.01019c7c))
        KEEP(*(.blob.01019cc0))
        KEEP(*(.blob.01019d34))
        KEEP(*(.blob.01019db8))
        KEEP(*(.blob.01019de8))
        KEEP(*(.blob.01019e48))
        KEEP(*(.blob.01019eb8))
        KEEP(*(.blob.01019f44))
        KEEP(*(.blob.01019f98))
        KEEP(*(.blob.01019ff0))
        KEEP(*(.blob.0101a044))
        KEEP(*(.blob.0101a098))
        KEEP(*(.blob.0101a0f0))
        KEEP(*(.blob.0101a154))
        KEEP(*(.blob.0101a1a8))
        KEEP(*(.blob.0101a200))
        KEEP(*(.blob.0101a254))
        KEEP(*(.blob.0101a2ac))
        KEEP(*(.blob.0101a304))
        KEEP(*(.blob.0101a390))
        KEEP(*(.blob.0101a468))
        KEEP(*(.blob.0101a540))
        KEEP(*(.blob.0101a564))
        KEEP(*(.blob.0101a570))
        KEEP(*(.blob.0101a718))
        KEEP(*(.blob.0101a730))
        KEEP(*(.text.FUN_0101a75c .text.startup.FUN_0101a75c))
        ASSERT(ABSOLUTE(.) == 0x0101a75e, "FUN_0101a75c is not its original size");
        KEEP(*(.blob.0101a75e))
        KEEP(*(.blob.0101a760))
        KEEP(*(.blob.0101a784))
        KEEP(*(.blob.0101a7a8))
        KEEP(*(.blob.0101a7b8))
        KEEP(*(.blob.0101a818))
        KEEP(*(.blob.0101a8f4))
        KEEP(*(.blob.0101a910))
        KEEP(*(.blob.0101a92c))
        KEEP(*(.blob.0101a9ac))
        KEEP(*(.text.FUN_0101a9dc .text.startup.FUN_0101a9dc))
        ASSERT(ABSOLUTE(.) == 0x0101a9de, "FUN_0101a9dc is not its original size");
        KEEP(*(.blob.0101a9de))
        KEEP(*(.blob.0101a9e0))
        KEEP(*(.blob.0101a9f0))
        KEEP(*(.blob.0101aa14))
        KEEP(*(.text.FUN_0101aa24 .text.startup.FUN_0101aa24))
        ASSERT(ABSOLUTE(.) == 0x0101aa26, "FUN_0101aa24 is not its original size");
        KEEP(*(.blob.0101aa26))
        KEEP(*(.blob.0101aa28))
        KEEP(*(.blob.0101aa6c))
        KEEP(*(.blob.0101abe0))
        KEEP(*(.blob.0101ac7c))
        KEEP(*(.blob.0101ace4))
        KEEP(*(.blob.0101ad2e))
        KEEP(*(.blob.0101ad98))
        KEEP(*(.blob.0101ae58))
        KEEP(*(.blob.0101aea4))
        KEEP(*(.blob.0101aef0))
        KEEP(*(.blob.0101b108))
        KEEP(*(.blob.0101b174))
        KEEP(*(.blob.0101b1b0))
        KEEP(*(.blob.0101b238))
        KEEP(*(.blob.0101b23c))
        KEEP(*(.blob.0101b242))
        KEEP(*(.blob.0101b274))
        KEEP(*(.blob.0101b2c4))
        KEEP(*(.blob.0101b318))
        KEEP(*(.blob.0101b326))
        KEEP(*(.blob.0101b33c))
        KEEP(*(.blob.0101b376))
        KEEP(*(.blob.0101b3c8))
        KEEP(*(.blob.0101b3d6))
        KEEP(*(.blob.0101b3ec))
        KEEP(*(.blob.0101b3ee))
        KEEP(*(.blob.0101b3fc))
        KEEP(*(.blob.0101b40a))
        KEEP(*(.blob.0101b472))
        KEEP(*(.blob.0101b482))
        KEEP(*(.text.FUN_0101b4ac .text.startup.FUN_0101b4ac))
        ASSERT(ABSOLUTE(.) == 0x0101b4ae, "FUN_0101b4ac is not its original size");
        KEEP(*(.blob.0101b4ae))
        KEEP(*(.blob.0101b4c0))
        KEEP(*(.blob.0101b4d8))
        KEEP(*(.blob.0101b4e0))
        KEEP(*(.blob.0101b4ec))
        KEEP(*(.blob.0101b4f8))
        KEEP(*(.blob.0101b504))
        KEEP(*(.blob.0101b5a0))
        KEEP(*(.blob.0101b5b0))
        KEEP(*(.blob.0101b5d8))
        KEEP(*(.blob.0101b61c))
        KEEP(*(.blob.0101b634))
        KEEP(*(.blob.0101b66c))
        KEEP(*(.blob.0101b690))
        KEEP(*(.blob.0101b750))
        KEEP(*(.blob.0101b8fc))
        KEEP(*(.blob.0101ba34))
        KEEP(*(.blob.0101ba98))
        KEEP(*(.blob.0101baba))
        KEEP(*(.blob.0101badc))
        KEEP(*(.blob.0101bafe))
        KEEP(*(.blob.0101bb20))
        KEEP(*(.blob.0101bb42))
        KEEP(*(.blob.0101bb78))
        KEEP(*(.blob.0101bbc4))
        KEEP(*(.blob.0101bc7c))
        KEEP(*(.blob.0101bd48))
        KEEP(*(.blob.0101be14))
        KEEP(*(.blob.0101be8c))
        KEEP(*(.text.FUN_0101c024 .text.startup.FUN_0101c024))
        ASSERT(ABSOLUTE(.) == 0x0101c034, "FUN_0101c024 is not its original size");
        KEEP(*(.blob.0101c034))
        KEEP(*(.blob.0101c0f0))
        KEEP(*(.blob.0101c144))
        KEEP(*(.blob.0101c190))
        KEEP(*(.blob.0101c22c))
        KEEP(*(.blob.0101c254))
        KEEP(*(.blob.0101c260))
        KEEP(*(.blob.0101c288))
        KEEP(*(.blob.0101c294))
        KEEP(*(.blob.0101c2a8))
        KEEP(*(.blob.0101c340))
        KEEP(*(.blob.0101c3a0))
        KEEP(*(.blob.0101c3ac))
        KEEP(*(.text.FUN_0101c414 .text.startup.FUN_0101c414))
        ASSERT(ABSOLUTE(.) == 0x0101c416, "FUN_0101c414 is not its original size");
        KEEP(*(.blob.0101c416))
        KEEP(*(.blob.0101c418))
        KEEP(*(.blob.0101c424))
        KEEP(*(.blob.0101c430))
        KEEP(*(.blob.0101c43c))
        KEEP(*(.blob.0101c44c))
        KEEP(*(.blob.0101c458))
        KEEP(*(.blob.0101c6cc))
        KEEP(*(.blob.0101c6d8))
        KEEP(*(.blob.0101c6f0))
        KEEP(*(.blob.0101c808))
        KEEP(*(.blob.0101c830))
        KEEP(*(.blob.0101c874))
        KEEP(*(.blob.0101c8ac))
        KEEP(*(.blob.0101c8d4))
        KEEP(*(.text.FUN_0101c8fc .text.startup.FUN_0101c8fc))
        ASSERT(ABSOLUTE(.) == 0x0101c8fe, "FUN_0101c8fc is not its original size");
        KEEP(*(.blob.0101c8fe))
        KEEP(*(.blob.0101c900))
        KEEP(*(.blob.0101ca14))
        KEEP(*(.blob.0101ca40))
        KEEP(*(.blob.0101cd48))
        KEEP(*(.blob.0101cda4))
        KEEP(*(.blob.0101cdc8))
        KEEP(*(.blob.0101cfe8))
        KEEP(*(.blob.0101d3e4))
        KEEP(*(.blob.0101d964))
        KEEP(*(.blob.0101db3c))
        KEEP(*(.blob.0101dbcc))
        KEEP(*(.blob.0101de3c))
        KEEP(*(.blob.0101ded0))
        KEEP(*(.blob.0101def4))
        KEEP(*(.text.FUN_0101e008 .text.startup.FUN_0101e008))
        ASSERT(ABSOLUTE(.) == 0x0101e01a, "FUN_0101e008 is not its original size");
        KEEP(*(.blob.0101e01a))
        KEEP(*(.blob.0101e01c))
        KEEP(*(.blob.0101e050))
        KEEP(*(.blob.0101e080))
        KEEP(*(.blob.0101e2fc))
        KEEP(*(.blob.0101e41c))
        KEEP(*(.blob.0101e598))
        KEEP(*(.text.FUN_0101e674 .text.startup.FUN_0101e674))
        ASSERT(ABSOLUTE(.) == 0x0101e676, "FUN_0101e674 is not its original size");
        KEEP(*(.blob.0101e676))
        KEEP(*(.blob.0101e678))
        KEEP(*(.blob.0101e77c))
        KEEP(*(.blob.0101e7a4))
        KEEP(*(.blob.0101e7ca))
        KEEP(*(.blob.0101e7d6))
        KEEP(*(.blob.0101e7e2))
        KEEP(*(.blob.0101e7f2))
        KEEP(*(.blob.0101e82c))
        KEEP(*(.blob.0101e880))
        KEEP(*(.blob.0101e888))
        KEEP(*(.blob.0101e89e))
        KEEP(*(.blob.0101e8d2))
        KEEP(*(.blob.0101e8fe))
        KEEP(*(.blob.0101e904))
        KEEP(*(.blob.0101e914))
        KEEP(*(.blob.0101e91c))
        KEEP(*(.blob.0101e924))
        KEEP(*(.blob.0101e948))
        KEEP(*(.blob.0101e958))
        KEEP(*(.blob.0101e95a))
        KEEP(*(.blob.0101e980))
        KEEP(*(.blob.0101e9d0))
        KEEP(*(.blob.0101eb50))
        KEEP(*(.blob.0101ec38))
        KEEP(*(.blob.0101ed1c))
        KEEP(*(.blob.0101ee04))
        KEEP(*(.blob.0101ee40))
        KEEP(*(.blob.0101ee50))
        KEEP(*(.blob.0101ee60))
        KEEP(*(.blob.0101eefc))
        KEEP(*(.blob.0101ef14))
        KEEP(*(.blob.0101ef2c))
        KEEP(*(.blob.0101ef48))
        KEEP(*(.blob.0101ef84))
        KEEP(*(.text.always_one .text.startup.always_one))
        ASSERT(ABSOLUTE(.) == 0x0101efa4, "always_one is not its original size");
        KEEP(*(.blob.0101efa4))
        KEEP(*(.blob.0101f080))
        KEEP(*(.text.FUN_0101f098 .text.startup.FUN_0101f098))
        ASSERT(ABSOLUTE(.) == 0x0101f09c, "FUN_0101f098 is not its original size");
        KEEP(*(.text.FUN_0101f09c .text.startup.FUN_0101f09c))
        ASSERT(ABSOLUTE(.) == 0x0101f0a0, "FUN_0101f09c is not its original size");
        KEEP(*(.blob.0101f0a0))
        KEEP(*(.blob.0101f0bc))
        KEEP(*(.blob.0101f0e4))
        KEEP(*(.blob.0101f1d4))
        KEEP(*(.blob.0101f60c))
        KEEP(*(.blob.0101f64c))
        KEEP(*(.blob.0101f718))
        KEEP(*(.blob.0101f798))
        KEEP(*(.blob.0101f7d0))
        KEEP(*(.text.FUN_0101f7d2 .text.startup.FUN_0101f7d2))
        ASSERT(ABSOLUTE(.) == 0x0101f7d4, "FUN_0101f7d2 is not its original size");
        KEEP(*(.blob.0101f7d4))
        KEEP(*(.blob.0101f940))
        KEEP(*(.text.log_empty .text.startup.log_empty))
        ASSERT(ABSOLUTE(.) == 0x0101f96c, "log_empty is not its original size");
        KEEP(*(.text.FUN_0101f96c .text.startup.FUN_0101f96c))
        ASSERT(ABSOLUTE(.) == 0x0101f98c, "FUN_0101f96c is not its original size");
        KEEP(*(.blob.0101f98c))
        KEEP(*(.blob.0101f9a0))
        KEEP(*(.blob.0101f9b8))
        KEEP(*(.text.FUN_0101fa34 .text.startup.FUN_0101fa34))
        ASSERT(ABSOLUTE(.) == 0x0101fa38, "FUN_0101fa34 is not its original size");
        KEEP(*(.blob.0101fa38))
        KEEP(*(.blob.0101fa44))
        KEEP(*(.blob.0101fa5c))
        KEEP(*(.blob.0101fa98))
        KEEP(*(.blob.0101fae0))
        KEEP(*(.blob.0101fb08))
        KEEP(*(.blob.0101fb14))
        KEEP(*(.blob.0101fb2c))
        KEEP(*(.blob.0101fb60))
        KEEP(*(.blob.0101fba0))
        KEEP(*(.blob.0101fbb8))
        KEEP(*(.blob.0101fbf0))
        KEEP(*(.blob.0101fc18))
        KEEP(*(.blob.0101fc30))
        KEEP(*(.blob.0101fc58))
        KEEP(*(.blob.0101ffac))
        KEEP(*(.blob.0101ffc8))
        KEEP(*(.blob.01020074))
        KEEP(*(.text.FUN_010200bc .text.startup.FUN_010200bc))
        ASSERT(ABSOLUTE(.) == 0x010200be, "FUN_010200bc is not its original size");
        KEEP(*(.blob.010200be))
        KEEP(*(.blob.01020118))
        KEEP(*(.blob.01020184))
        KEEP(*(.blob.01020210))
        KEEP(*(.blob.0102024c))
        KEEP(*(.text.FUN_010202a0 .text.startup.FUN_010202a0))
        ASSERT(ABSOLUTE(.) == 0x010202a2, "FUN_010202a0 is not its original size");
        KEEP(*(.blob.010202a2))
        KEEP(*(.blob.010202a4))
        KEEP(*(.blob.010202c8))
        KEEP(*(.blob.010202f2))
        KEEP(*(.blob.01020316))
        KEEP(*(.text.FUN_01020340 .text.startup.FUN_01020340))
        ASSERT(ABSOLUTE(.) == 0x01020342, "FUN_01020340 is not its original size");
        KEEP(*(.blob.01020342))
        KEEP(*(.blob.01020344))
        KEEP(*(.text.FUN_01020350 .text.startup.FUN_01020350))
        ASSERT(ABSOLUTE(.) == 0x01020352, "FUN_01020350 is not its original size");
        KEEP(*(.text.FUN_01020352 .text.startup.FUN_01020352))
        ASSERT(ABSOLUTE(.) == 0x01020354, "FUN_01020352 is not its original size");
        KEEP(*(.blob.01020354))
        KEEP(*(.blob.01020364))
        KEEP(*(.blob.01020374))
        KEEP(*(.blob.010203b0))
        KEEP(*(.blob.010203c0))
        KEEP(*(.blob.010203d0))
        KEEP(*(.blob.010203e0))
        KEEP(*(.blob.010203f0))
        KEEP(*(.blob.01020400))
        KEEP(*(.blob.0102041c))
        KEEP(*(.blob.01020464))
        KEEP(*(.blob.010204bc))
        KEEP(*(.blob.01020500))
        KEEP(*(.blob.01020544))
        KEEP(*(.text.FUN_0102055c .text.startup.FUN_0102055c))
        ASSERT(ABSOLUTE(.) == 0x0102056c, "FUN_0102055c is not its original size");
        KEEP(*(.blob.0102056c))
        KEEP(*(.blob.0102059c))
        KEEP(*(.blob.010205e0))
        KEEP(*(.blob.01020688))
        KEEP(*(.blob.010206ca))
        KEEP(*(.blob.010206f0))
        KEEP(*(.blob.01020a50))
        KEEP(*(.blob.01020b14))
        KEEP(*(.text.FUN_01020b8c .text.startup.FUN_01020b8c))
        ASSERT(ABSOLUTE(.) == 0x01020b8e, "FUN_01020b8c is not its original size");
        KEEP(*(.text.FUN_01020b8e .text.startup.FUN_01020b8e))
        ASSERT(ABSOLUTE(.) == 0x01020b90, "FUN_01020b8e is not its original size");
        KEEP(*(.blob.01020b90))
        KEEP(*(.blob.01020b9c))
        KEEP(*(.blob.01020bf8))
        KEEP(*(.blob.01020c1c))
        KEEP(*(.blob.01020c60))
        KEEP(*(.blob.01020d38))
        KEEP(*(.blob.01020dc8))
        KEEP(*(.blob.01020de4))
        KEEP(*(.blob.01020e08))
        KEEP(*(.blob.01020e74))
        KEEP(*(.blob.01020edc))
        KEEP(*(.blob.01020ef8))
        KEEP(*(.blob.01020f16))
        KEEP(*(.blob.01020f60))
        KEEP(*(.blob.01020f7a))
        KEEP(*(.blob.01020f8a))
        KEEP(*(.blob.01020fae))
        KEEP(*(.blob.01020fc6))
        KEEP(*(.blob.01020ffe))
        KEEP(*(.blob.010210b2))
        KEEP(*(.blob.010210b8))
        KEEP(*(.blob.010210d6))
        KEEP(*(.blob.01021108))
        KEEP(*(.blob.01021158))
        KEEP(*(.blob.01021172))
        KEEP(*(.blob.0102118a))
        KEEP(*(.blob.010211b2))
        KEEP(*(.blob.010211c2))
        KEEP(*(.blob.010211da))
        KEEP(*(.blob.010211f2))
        KEEP(*(.blob.0102120a))
        KEEP(*(.blob.01021230))
        KEEP(*(.blob.01021248))
        KEEP(*(.blob.01021260))
        KEEP(*(.blob.0102126e))
        KEEP(*(.blob.01021278))
        KEEP(*(.blob.01021282))
        KEEP(*(.blob.010212c0))
        KEEP(*(.blob.010212d4))
        KEEP(*(.blob.01021320))
        KEEP(*(.blob.0102136e))
        KEEP(*(.blob.01021374))
        KEEP(*(.blob.01021398))
        KEEP(*(.blob.010213c8))
        KEEP(*(.blob.01021422))
        KEEP(*(.blob.0102143c))
        KEEP(*(.blob.010214a4))
        KEEP(*(.blob.010214e2))
        KEEP(*(.blob.010214ea))
        KEEP(*(.blob.010214f6))
        KEEP(*(.blob.01021506))
        KEEP(*(.blob.01021512))
        KEEP(*(.blob.01021536))
        KEEP(*(.blob.010215ae))
        KEEP(*(.blob.010215b0))
        KEEP(*(.blob.010215b2))
        KEEP(*(.blob.010215e8))
        KEEP(*(.blob.010215f4))
        KEEP(*(.blob.01021604))
        KEEP(*(.blob.01021784))
        KEEP(*(.blob.010217fc))
        KEEP(*(.blob.01021836))
        KEEP(*(.blob.01021850))
        KEEP(*(.blob.0102186c))
        KEEP(*(.blob.01021964))
        KEEP(*(.blob.010219dc))
        KEEP(*(.blob.01021a12))
        KEEP(*(.blob.01021a36))
        KEEP(*(.blob.01021a60))
        KEEP(*(.blob.01021ac0))
        KEEP(*(.blob.01021af0))
        KEEP(*(.blob.01021bc0))
        KEEP(*(.blob.01021ca8))
        KEEP(*(.blob.01021cc4))
        KEEP(*(.blob.01021cce))
        KEEP(*(.blob.01021ce8))
        KEEP(*(.blob.01021cf2))
        KEEP(*(.blob.01021cfc))
        KEEP(*(.blob.01021d06))
        KEEP(*(.blob.01021d30))
        KEEP(*(.blob.01021d3a))
        KEEP(*(.blob.01021d3c))
        KEEP(*(.blob.01021d46))
        KEEP(*(.blob.01021d54))
        KEEP(*(.blob.01021ec4))
        KEEP(*(.blob.01021f1a))
        KEEP(*(.blob.01021f40))
        KEEP(*(.blob.01021fa0))
        KEEP(*(.text.FUN_01021faa .text.startup.FUN_01021faa))
        ASSERT(ABSOLUTE(.) == 0x01021fac, "FUN_01021faa is not its original size");
        KEEP(*(.blob.01021fac))
        KEEP(*(.blob.01022002))
        KEEP(*(.blob.0102201c))
        KEEP(*(.blob.01022044))
        KEEP(*(.blob.010220bc))
        KEEP(*(.blob.01022104))
        KEEP(*(.blob.0102210e))
        KEEP(*(.blob.01022114))
        KEEP(*(.blob.010221c0))
        KEEP(*(.blob.01022274))
        KEEP(*(.text.FUN_01022314 .text.startup.FUN_01022314))
        ASSERT(ABSOLUTE(.) == 0x01022316, "FUN_01022314 is not its original size");
        KEEP(*(.blob.01022316))
        KEEP(*(.text.FUN_01022318 .text.startup.FUN_01022318))
        ASSERT(ABSOLUTE(.) == 0x01022328, "FUN_01022318 is not its original size");
        KEEP(*(.text.FUN_01022328 .text.startup.FUN_01022328))
        ASSERT(ABSOLUTE(.) == 0x0102232a, "FUN_01022328 is not its original size");
        KEEP(*(.blob.0102232a))
        KEEP(*(.blob.01022330))
        KEEP(*(.blob.0102240c))
        KEEP(*(.blob.0102244a))
        KEEP(*(.blob.01022488))
        KEEP(*(.blob.0102249c))
        KEEP(*(.blob.010224bc))
        KEEP(*(.blob.010225f0))
        KEEP(*(.blob.01022614))
        KEEP(*(.blob.010226a4))
        KEEP(*(.blob.010226dc))
        KEEP(*(.blob.01022724))
        KEEP(*(.blob.01022754))
        KEEP(*(.blob.01022768))
        KEEP(*(.blob.010227dc))
        KEEP(*(.blob.01022820))
        KEEP(*(.blob.01022844))
        KEEP(*(.blob.010228bc))
        KEEP(*(.blob.01022938))
        KEEP(*(.blob.01022998))
        KEEP(*(.blob.01022a00))
        KEEP(*(.blob.01022a20))
        KEEP(*(.text.FUN_01022aec .text.startup.FUN_01022aec))
        ASSERT(ABSOLUTE(.) == 0x01022aee, "FUN_01022aec is not its original size");
        KEEP(*(.blob.01022aee))
        KEEP(*(.blob.01022af0))
        KEEP(*(.blob.01022b18))
        KEEP(*(.blob.01022c48))
        KEEP(*(.blob.01022ca4))
        KEEP(*(.blob.01022d0c))
        KEEP(*(.blob.01022e14))
        KEEP(*(.text.FUN_01022e8c .text.startup.FUN_01022e8c))
        ASSERT(ABSOLUTE(.) == 0x01022ea0, "FUN_01022e8c is not its original size");
        KEEP(*(.blob.01022ea0))
        KEEP(*(.blob.01022f2a))
        KEEP(*(.blob.01022f48))
        KEEP(*(.blob.01022f74))
        KEEP(*(.blob.01023004))
        KEEP(*(.blob.010230a4))
        KEEP(*(.blob.010230c4))
        KEEP(*(.blob.010230c6))
        KEEP(*(.blob.010230ec))
        KEEP(*(.blob.01023108))
        KEEP(*(.blob.01023148))
        KEEP(*(.text.restart .text.startup.restart))
        ASSERT(ABSOLUTE(.) == 0x010232ae, "restart is not its original size");
        KEEP(*(.blob.010232ae))
        KEEP(*(.blob.010232b0))
        KEEP(*(.blob.010232bc))
        KEEP(*(.text.FUN_0102332a .text.startup.FUN_0102332a))
        ASSERT(ABSOLUTE(.) == 0x0102332c, "FUN_0102332a is not its original size");
        KEEP(*(.text.FUN_0102332c .text.startup.FUN_0102332c))
        ASSERT(ABSOLUTE(.) == 0x0102332e, "FUN_0102332c is not its original size");
        KEEP(*(.text.FUN_0102332e .text.startup.FUN_0102332e))
        ASSERT(ABSOLUTE(.) == 0x01023330, "FUN_0102332e is not its original size");
        KEEP(*(.text.FUN_01023330 .text.startup.FUN_01023330))
        ASSERT(ABSOLUTE(.) == 0x01023332, "FUN_01023330 is not its original size");
        KEEP(*(.blob.01023332))
        KEEP(*(.blob.0102333a))
        KEEP(*(.text.FUN_01023340 .text.startup.FUN_01023340))
        ASSERT(ABSOLUTE(.) == 0x01023342, "FUN_01023340 is not its original size");
        KEEP(*(.blob.01023342))
        KEEP(*(.blob.01023350))
        KEEP(*(.text.sdk_assert .text.startup.sdk_assert))
        ASSERT(ABSOLUTE(.) == 0x01023354, "sdk_assert is not its original size");
        KEEP(*(.blob.01023354))
        KEEP(*(.blob.01023380))
        KEEP(*(.blob.01023398))
        KEEP(*(.blob.010233b8))
        KEEP(*(.blob.010234c8))
        KEEP(*(.blob.010238f0))
        KEEP(*(.blob.01023910))
        KEEP(*(.blob.0102393c))
        KEEP(*(.blob.010239cc))
        KEEP(*(.blob.01023a50))
        KEEP(*(.blob.01023a5c))
        KEEP(*(.blob.01023a90))
        KEEP(*(.blob.01023ad0))
        KEEP(*(.text.FUN_01023ae8 .text.startup.FUN_01023ae8))
        ASSERT(ABSOLUTE(.) == 0x01023aea, "FUN_01023ae8 is not its original size");
        KEEP(*(.blob.01023aea))
        KEEP(*(.text.FUN_01023b04 .text.startup.FUN_01023b04))
        ASSERT(ABSOLUTE(.) == 0x01023b08, "FUN_01023b04 is not its original size");
        KEEP(*(.blob.01023b08))
        KEEP(*(.blob.01023b22))
        KEEP(*(.blob.01023b4c))
        KEEP(*(.blob.01023bb4))
        KEEP(*(.blob.01023c5c))
        KEEP(*(.blob.01023c90))
        KEEP(*(.blob.01023cfc))
        KEEP(*(.blob.01023d5c))
        KEEP(*(.blob.01023d74))
        KEEP(*(.blob.01023dd0))
        KEEP(*(.blob.01023de4))
        KEEP(*(.blob.01023e64))
        KEEP(*(.text.FUN_01023e6c .text.startup.FUN_01023e6c))
        ASSERT(ABSOLUTE(.) == 0x01023e6e, "FUN_01023e6c is not its original size");
        KEEP(*(.blob.01023e6e))
        KEEP(*(.blob.01023e76))
        KEEP(*(.blob.01023e7c))
        KEEP(*(.blob.01023e7e))
        KEEP(*(.blob.01023e80))
        KEEP(*(.text.FUN_01023efc .text.startup.FUN_01023efc))
        ASSERT(ABSOLUTE(.) == 0x01023f04, "FUN_01023efc is not its original size");
        KEEP(*(.blob.01023f04))
        KEEP(*(.blob.01023f10))
        KEEP(*(.blob.01023f24))
        KEEP(*(.blob.01023f50))
        KEEP(*(.blob.01023f64))
        KEEP(*(.blob.01023f7c))
        KEEP(*(.blob.01023f9c))
        KEEP(*(.blob.01023fb8))
        KEEP(*(.blob.01023fcc))
        KEEP(*(.blob.01024030))
        KEEP(*(.blob.01024044))
        KEEP(*(.blob.01024090))
        KEEP(*(.text.FUN_010240a8 .text.startup.FUN_010240a8))
        ASSERT(ABSOLUTE(.) == 0x010240ac, "FUN_010240a8 is not its original size");
        KEEP(*(.blob.010240ac))
        KEEP(*(.text.FUN_010240c8 .text.startup.FUN_010240c8))
        ASSERT(ABSOLUTE(.) == 0x010240cc, "FUN_010240c8 is not its original size");
        KEEP(*(.blob.010240cc))
        KEEP(*(.blob.01024114))
        KEEP(*(.blob.01024150))
        KEEP(*(.blob.0102415c))
        KEEP(*(.blob.0102416c))
        KEEP(*(.text.FUN_0102417c .text.startup.FUN_0102417c))
        ASSERT(ABSOLUTE(.) == 0x01024194, "FUN_0102417c is not its original size");
        KEEP(*(.blob.01024194))
        KEEP(*(.text.FUN_010241c4 .text.startup.FUN_010241c4))
        ASSERT(ABSOLUTE(.) == 0x010241c6, "FUN_010241c4 is not its original size");
        KEEP(*(.blob.010241c6))
        KEEP(*(.blob.010241c8))
        KEEP(*(.blob.010241dc))
        KEEP(*(.blob.010241fa))
        KEEP(*(.blob.01024264))
        KEEP(*(.blob.01024284))
        KEEP(*(.blob.010242b8))
        KEEP(*(.text.FUN_010242e4 .text.startup.FUN_010242e4))
        ASSERT(ABSOLUTE(.) == 0x010242f0, "FUN_010242e4 is not its original size");
        KEEP(*(.blob.010242f0))
        KEEP(*(.blob.01024584))
        KEEP(*(.text.FUN_01024798 .text.startup.FUN_01024798))
        ASSERT(ABSOLUTE(.) == 0x0102479a, "FUN_01024798 is not its original size");
        KEEP(*(.blob.0102479a))
        KEEP(*(.blob.0102479c))
        KEEP(*(.blob.010247c4))
        KEEP(*(.blob.010247e8))
        KEEP(*(.blob.01024838))
        KEEP(*(.blob.010248e0))
        KEEP(*(.blob.01024900))
        KEEP(*(.blob.01024910))
        KEEP(*(.blob.0102492c))
        KEEP(*(.blob.01024980))
        KEEP(*(.blob.01024994))
        KEEP(*(.text.FUN_010249c2 .text.startup.FUN_010249c2))
        ASSERT(ABSOLUTE(.) == 0x010249c4, "FUN_010249c2 is not its original size");
        KEEP(*(.text.FUN_010249c4 .text.startup.FUN_010249c4))
        ASSERT(ABSOLUTE(.) == 0x010249ce, "FUN_010249c4 is not its original size");
        KEEP(*(.blob.010249ce))
        KEEP(*(.blob.010249e6))
        KEEP(*(.blob.010249ee))
        KEEP(*(.blob.01024a08))
        KEEP(*(.blob.01024a54))
        KEEP(*(.blob.01024a7c))
        KEEP(*(.blob.01024a84))
        KEEP(*(.blob.01024a9c))
        KEEP(*(.blob.01024ab4))
        KEEP(*(.blob.01024ad0))
        KEEP(*(.blob.01024b14))
        KEEP(*(.blob.01024b28))
        KEEP(*(.blob.01024b54))
        KEEP(*(.text.FUN_01024bb8 .text.startup.FUN_01024bb8))
        ASSERT(ABSOLUTE(.) == 0x01024bba, "FUN_01024bb8 is not its original size");
        KEEP(*(.text.FUN_01024bba .text.startup.FUN_01024bba))
        ASSERT(ABSOLUTE(.) == 0x01024bbc, "FUN_01024bba is not its original size");
        KEEP(*(.text.FUN_01024bbc .text.startup.FUN_01024bbc))
        ASSERT(ABSOLUTE(.) == 0x01024bbe, "FUN_01024bbc is not its original size");
        KEEP(*(.blob.01024bbe))
        KEEP(*(.blob.01024bc0))
        KEEP(*(.text.FUN_01024bcc .text.startup.FUN_01024bcc))
        ASSERT(ABSOLUTE(.) == 0x01024bce, "FUN_01024bcc is not its original size");
        KEEP(*(.blob.01024bce))
        KEEP(*(.blob.01024bd0))
        KEEP(*(.blob.01024bec))
        KEEP(*(.blob.01024c60))
        KEEP(*(.blob.01024cac))
        KEEP(*(.blob.01024ce4))
        KEEP(*(.blob.01024d0c))
        KEEP(*(.text.FUN_01024d78 .text.startup.FUN_01024d78))
        ASSERT(ABSOLUTE(.) == 0x01024d7a, "FUN_01024d78 is not its original size");
        KEEP(*(.blob.01024d7a))
        KEEP(*(.blob.01024d7c))
        KEEP(*(.blob.01024dc8))
        KEEP(*(.blob.01024de0))
        KEEP(*(.blob.01024e24))
        KEEP(*(.blob.01024e80))
        KEEP(*(.blob.01024e8c))
        KEEP(*(.blob.01024ea2))
        KEEP(*(.blob.01024eb8))
        KEEP(*(.blob.01024edc))
        KEEP(*(.blob.01024f48))
        KEEP(*(.blob.01024fbc))
        KEEP(*(.blob.01025000))
        KEEP(*(.blob.01025008))
        KEEP(*(.blob.01025018))
        KEEP(*(.blob.01025054))
        KEEP(*(.blob.0102507c))
        KEEP(*(.blob.010250a8))
        KEEP(*(.blob.010250c0))
        KEEP(*(.blob.010250e4))
        KEEP(*(.blob.010250f6))
        KEEP(*(.blob.01025110))
        KEEP(*(.blob.0102513c))
        KEEP(*(.blob.01025150))
        KEEP(*(.blob.01025154))
        KEEP(*(.blob.010251b0))
        KEEP(*(.blob.01025668))
        KEEP(*(.blob.0102566a))
        KEEP(*(.blob.010259b4))
        KEEP(*(.blob.010259e8))
        KEEP(*(.blob.01025a64))
    }
    /DISCARD/ : { *(.text) *(.data) *(.bss) *(.ARM.attributes) *(.comment) *(.note*) }
}

DAT_0002179d = 0x0002179d;
DAT_000206da = 0x000206da;
_DAT_00020020 = 0x00020020;
STR_01022f14 = 0x01022f14;
DAT_00020000 = 0x00020000;
_DAT_000201f2 = 0x000201f2;
DAT_000206b1 = 0x000206b1;
DAT_00020139 = 0x00020139;
DAT_000210a5 = 0x000210a5;
DAT_000206d0 = 0x000206d0;
DAT_00020158 = 0x00020158;
_DAT_00020340 = 0x00020340;
_DAT_000200dc = 0x000200dc;
_DAT_0800001c = 0x0800001c;
STR_01027904 = 0x01027904;
_DAT_0002fff4 = 0x0002fff4;
DAT_0002013c = 0x0002013c;
DAT_00020039 = 0x00020039;
DAT_0002179c = 0x0002179c;
DAT_01027f59 = 0x01027f59;
_DAT_00021868 = 0x00021868;
DAT_00020167 = 0x00020167;
_DAT_00020027 = 0x00020027;
DAT_000c804d = 0x000c804d;
_DAT_000f8800 = 0x000f8800;
_DAT_00021902 = 0x00021902;
UNK_0000800f = 0x0000800f;
STR_0101fde4 = 0x0101fde4;
STR_01029184 = 0x01029184;
DAT_0102813d = 0x0102813d;
_DAT_00020318 = 0x00020318;
_DAT_000f850e = 0x000f850e;
_DAT_e000e100 = 0xe000e100;
DAT_010279dc = 0x010279dc;
DAT_000200f0 = 0x000200f0;
_DAT_00020128 = 0x00020128;
STR_01020b58 = 0x01020b58;
DAT_00020132 = 0x00020132;
DAT_00022030 = 0x00022030;
DAT_000206d9 = 0x000206d9;
DAT_000c8024 = 0x000c8024;
DAT_00020714 = 0x00020714;
DAT_01029532 = 0x01029532;
DAT_0002062d = 0x0002062d;
_DAT_00020030 = 0x00020030;
DAT_00021928 = 0x00021928;
DAT_0002030c = 0x0002030c;
STR_01023270 = 0x01023270;
DAT_0002035a = 0x0002035a;
DAT_00020184 = 0x00020184;
DAT_000f6018 = 0x000f6018;
DAT_0002187c = 0x0002187c;
DAT_00020785 = 0x00020785;
_DAT_000205f4 = 0x000205f4;
DAT_00020309 = 0x00020309;
DAT_000206c0 = 0x000206c0;
DAT_000f853c = 0x000f853c;
_DAT_000201e4 = 0x000201e4;
DAT_0102982c = 0x0102982c;
DAT_000c8023 = 0x000c8023;
DAT_000f6003 = 0x000f6003;
DAT_00021554 = 0x00021554;
STR_01020154 = 0x01020154;
STR_0101965c = 0x0101965c;
DAT_000f6026 = 0x000f6026;
DAT_00020774 = 0x00020774;
_DAT_000f8810 = 0x000f8810;
DAT_000215dd = 0x000215dd;
DAT_000c8010 = 0x000c8010;
STR_0101bd1c = 0x0101bd1c;
STR_01019830 = 0x01019830;
_DAT_000f8564 = 0x000f8564;
DAT_010180ac = 0x010180ac;
_DAT_00020150 = 0x00020150;
STR_0101ff14 = 0x0101ff14;
DAT_00020634 = 0x00020634;
DAT_000c8972 = 0x000c8972;
DAT_000210a3 = 0x000210a3;
STR_01023cc0 = 0x01023cc0;
_DAT_00020f90 = 0x00020f90;
DAT_01029542 = 0x01029542;
DAT_00020658 = 0x00020658;
STR_01023ffc = 0x01023ffc;
_DAT_0002012c = 0x0002012c;
_DAT_000201de = 0x000201de;
_DAT_0002032a = 0x0002032a;
DAT_00020027 = 0x00020027;
DAT_0002179e = 0x0002179e;
_DAT_00020638 = 0x00020638;
_DAT_00021880 = 0x00021880;
DAT_01027fbf = 0x01027fbf;
STR_010191d0 = 0x010191d0;
_DAT_00021870 = 0x00021870;
STR_0101ff8c = 0x0101ff8c;
STR_01027841 = 0x01027841;
DAT_000206b0 = 0x000206b0;
DAT_00020138 = 0x00020138;
DAT_000200ec = 0x000200ec;
_DAT_000201d4 = 0x000201d4;
DAT_000210a4 = 0x000210a4;
DAT_010282df = 0x010282df;
_DAT_000201c0 = 0x000201c0;
DAT_00020182 = 0x00020182;
DAT_00020168 = 0x00020168;
STR_0101b724 = 0x0101b724;
DAT_00004248 = 0x00004248;
DAT_000c804e = 0x000c804e;
_DAT_e000e014 = 0xe000e014;
_DAT_00020140 = 0x00020140;
DAT_00022ac2 = 0x00022ac2;
DAT_00020131 = 0x00020131;
STR_010222f4 = 0x010222f4;
DAT_000201b2 = 0x000201b2;
PTR_DAT_010283b8 = 0x010283b8;
DAT_0002018c = 0x0002018c;
_DAT_000202bc = 0x000202bc;
_DAT_00020348 = 0x00020348;
_DAT_00020010 = 0x00020010;
DAT_00001770 = 0x00001770;
STR_010221a4 = 0x010221a4;
DAT_0002062c = 0x0002062c;
_DAT_00020648 = 0x00020648;
DAT_000f6019 = 0x000f6019;
DAT_00020185 = 0x00020185;
STR_0101ff9c = 0x0101ff9c;
DAT_01025a6e = 0x01025a6e;
DAT_00002c65 = 0x00002c65;
STR_01019d94 = 0x01019d94;
STR_01019630 = 0x01019630;
_DAT_000f8808 = 0x000f8808;
DAT_00020786 = 0x00020786;
_DAT_00020310 = 0x00020310;
_DAT_e000e180 = 0xe000e180;
DAT_000206c1 = 0x000206c1;
STR_010220e4 = 0x010220e4;
DAT_000200e4 = 0x000200e4;
DAT_01027f8e = 0x01027f8e;
DAT_000f6002 = 0x000f6002;
DAT_000201cd = 0x000201cd;
DAT_00021920 = 0x00021920;
DAT_00020332 = 0x00020332;
DAT_010292ec = 0x010292ec;
STR_0101acd0 = 0x0101acd0;
DAT_000c8905 = 0x000c8905;
DAT_00020777 = 0x00020777;
_DAT_00020620 = 0x00020620;
STR_01023d90 = 0x01023d90;
_DAT_08000024 = 0x08000024;
_DAT_00020170 = 0x00020170;
_DAT_000f0c4c = 0x000f0c4c;
_DAT_000201bc = 0x000201bc;
_DAT_00020044 = 0x00020044;
_DAT_00020708 = 0x00020708;
DAT_0000176f = 0x0000176f;
_DAT_00020124 = 0x00020124;
DAT_00020635 = 0x00020635;
DAT_000c8973 = 0x000c8973;
DAT_000210a2 = 0x000210a2;
STR_01023b90 = 0x01023b90;
DAT_00004650 = 0x00004650;
STR_01022028 = 0x01022028;
DAT_00020120 = 0x00020120;
_DAT_00020338 = 0x00020338;
DAT_01028745 = 0x01028745;
DAT_00020659 = 0x00020659;
DAT_0002063c = 0x0002063c;
DAT_00020026 = 0x00020026;
DAT_000206dc = 0x000206dc;
DAT_00020324 = 0x00020324;
_DAT_00021924 = 0x00021924;
STR_0101c38c = 0x0101c38c;
UNK_0102956b = 0x0102956b;
_DAT_000206c4 = 0x000206c4;
DAT_0002058c = 0x0002058c;
DAT_01027fe3 = 0x01027fe3;
STR_01029103 = 0x01029103;
_DAT_000201f4 = 0x000201f4;
DAT_00021fa4 = 0x00021fa4;
DAT_000201b4 = 0x000201b4;
DAT_01029500 = 0x01029500;
DAT_010180b0 = 0x010180b0;
DAT_00020650 = 0x00020650;
_DAT_00020008 = 0x00020008;
DAT_00021864 = 0x00021864;
DAT_01027bfa = 0x01027bfa;
DAT_01028047 = 0x01028047;
_DAT_00020160 = 0x00020160;
DAT_00020183 = 0x00020183;
DAT_00020130 = 0x00020130;
STR_01021f7c = 0x01021f7c;
STR_0101c37c = 0x0101c37c;
_DAT_0002063c = 0x0002063c;
STR_01023e24 = 0x01023e24;
_DAT_0002016c = 0x0002016c;
_DAT_000201c8 = 0x000201c8;
DAT_00020712 = 0x00020712;
STR_0101fec0 = 0x0101fec0;
DAT_000c8043 = 0x000c8043;
DAT_000215da = 0x000215da;
DAT_000f8804 = 0x000f8804;
_DAT_000f881c = 0x000f881c;
DAT_0000e417 = 0x0000e417;
_DAT_0002191e = 0x0002191e;
_DAT_00020710 = 0x00020710;
DAT_000206bf = 0x000206bf;
STR_01022f34 = 0x01022f34;
_DAT_0002015a = 0x0002015a;
DAT_000210ab = 0x000210ab;
_DAT_00020640 = 0x00020640;
DAT_000f880c = 0x000f880c;
DAT_000201cc = 0x000201cc;
DAT_00021927 = 0x00021927;
DAT_00021f60 = 0x00021f60;
DAT_00020682 = 0x00020682;
STR_0101fe90 = 0x0101fe90;
_DAT_0002033c = 0x0002033c;
STR_01019d14 = 0x01019d14;
_DAT_00022024 = 0x00022024;
DAT_01027a00 = 0x01027a00;
DAT_000c8970 = 0x000c8970;
_DAT_000f0c48 = 0x000f0c48;
DAT_00021fe8 = 0x00021fe8;
STR_01019690 = 0x01019690;
_DAT_0002fff0 = 0x0002fff0;
DAT_01027a24 = 0x01027a24;
DAT_01028c2c = 0x01028c2c;
STR_010283e0 = 0x010283e0;
STR_010279a3 = 0x010279a3;
DAT_000206db = 0x000206db;
PTR_FUN_01023f24_1_01029158 = 0x01029158;
STR_01027895 = 0x01027895;
STR_01027828 = 0x01027828;
DAT_00020005 = 0x00020005;
UNK_00000002 = 0x00000002;
_DAT_00020628 = 0x00020628;
_DAT_00020700 = 0x00020700;
DAT_00020136 = 0x00020136;
DAT_000201b5 = 0x000201b5;
DAT_0102946c = 0x0102946c;
DAT_0102823e = 0x0102823e;
DAT_0002015c = 0x0002015c;
_DAT_000200d8 = 0x000200d8;
DAT_00002c60 = 0x00002c60;
DAT_000c804c = 0x000c804c;
STR_01023130 = 0x01023130;
DAT_01027c23 = 0x01027c23;
DAT_00022ac4 = 0x00022ac4;
DAT_0002017f = 0x0002017f;
DAT_00021901 = 0x00021901;
DAT_000201e9 = 0x000201e9;
_DAT_00020334 = 0x00020334;
_DAT_000201e0 = 0x000201e0;
DAT_01028f07 = 0x01028f07;
_DAT_00020358 = 0x00020358;
DAT_010279ca = 0x010279ca;
DAT_000201f6 = 0x000201f6;
DAT_000219a8 = 0x000219a8;
_DAT_000f8560 = 0x000f8560;
_DAT_000206c8 = 0x000206c8;
DAT_00021ed0 = 0x00021ed0;
DAT_01027be3 = 0x01027be3;
DAT_01028111 = 0x01028111;
_DAT_000201f8 = 0x000201f8;
STR_010238c8 = 0x010238c8;
DAT_0102969d = 0x0102969d;
DAT_010291ac = 0x010291ac;
DAT_000f872b = 0x000f872b;
DAT_000217b2 = 0x000217b2;
_DAT_08003424 = 0x08003424;
STR_010222e0 = 0x010222e0;
DAT_01028148 = 0x01028148;
_DAT_000201b2 = 0x000201b2;
_DAT_0002058a = 0x0002058a;
DAT_000206be = 0x000206be;
STR_010238dc = 0x010238dc;
STR_0101fe64 = 0x0101fe64;
STR_01019600 = 0x01019600;
DAT_000210aa = 0x000210aa;
DAT_0102984c = 0x0102984c;
DAT_000f6004 = 0x000f6004;
DAT_000201a8 = 0x000201a8;
DAT_00021926 = 0x00021926;
_DAT_000202c0 = 0x000202c0;
STR_01019e9c = 0x01019e9c;
DAT_000201ea = 0x000201ea;
DAT_00020779 = 0x00020779;
DAT_00020003 = 0x00020003;
_DAT_00021874 = 0x00021874;
STR_01020d9c = 0x01020d9c;
_DAT_00020f9c = 0x00020f9c;
STR_0101ac50 = 0x0101ac50;
DAT_01028420 = 0x01028420;
STR_010195c8 = 0x010195c8;
_DAT_000206a0 = 0x000206a0;
DAT_000c8971 = 0x000c8971;
STR_0102406c = 0x0102406c;
DAT_000f8e0c = 0x000f8e0c;
DAT_0102800c = 0x0102800c;
DAT_00020345 = 0x00020345;
DAT_00020028 = 0x00020028;
_DAT_00021922 = 0x00021922;
DAT_000f6012 = 0x000f6012;
DAT_000206de = 0x000206de;
DAT_01027bd1 = 0x01027bd1;
DAT_00020004 = 0x00020004;
DAT_01027d66 = 0x01027d66;
STR_0101fe0c = 0x0101fe0c;
STR_0101ca04 = 0x0101ca04;
DAT_000201b6 = 0x000201b6;
DAT_00020135 = 0x00020135;
DAT_0102812c = 0x0102812c;
DAT_000210a9 = 0x000210a9;
_DAT_0002192c = 0x0002192c;
DAT_00021878 = 0x00021878;
PTR_FUN_01022318_1_010180fc = 0x010180fc;
DAT_00020717 = 0x00020717;
DAT_01028244 = 0x01028244;
DAT_01027fd1 = 0x01027fd1;
STR_0101edd8 = 0x0101edd8;
STR_0101bb4c = 0x0101bb4c;
STR_0101a444 = 0x0101a444;
DAT_00020181 = 0x00020181;
_DAT_00022054 = 0x00022054;
_DAT_000219a8 = 0x000219a8;
_DAT_00020f8c = 0x00020f8c;
_DAT_000f8804 = 0x000f8804;
_DAT_000200ec = 0x000200ec;
DAT_000f8522 = 0x000f8522;
DAT_000201e8 = 0x000201e8;
DAT_00021900 = 0x00021900;
DAT_01027aad = 0x01027aad;
DAT_00006f80 = 0x00006f80;
DAT_00021798 = 0x00021798;
_DAT_00020198 = 0x00020198;
_DAT_0002186c = 0x0002186c;
STR_0101bb98 = 0x0101bb98;
DAT_000201f7 = 0x000201f7;
DAT_00020710 = 0x00020710;
DAT_00022060 = 0x00022060;
_DAT_00020034 = 0x00020034;
DAT_00020773 = 0x00020773;
_DAT_08000020 = 0x08000020;
_DAT_00020174 = 0x00020174;
DAT_01027f69 = 0x01027f69;
DAT_000215dc = 0x000215dc;
STR_0101ff38 = 0x0101ff38;
_DAT_00020040 = 0x00020040;
DAT_00020060 = 0x00020060;
DAT_000210eb = 0x000210eb;
STR_0102781c = 0x0102781c;
DAT_000215d9 = 0x000215d9;
DAT_000206bd = 0x000206bd;
STR_01022188 = 0x01022188;
STR_01027990 = 0x01027990;
DAT_01028400 = 0x01028400;
DAT_00020002 = 0x00020002;
_DAT_00020304 = 0x00020304;
_DAT_000201f0 = 0x000201f0;
DAT_000201b8 = 0x000201b8;
DAT_000206b3 = 0x000206b3;
_DAT_00020154 = 0x00020154;
DAT_00003431 = 0x00003431;
_DAT_00020f94 = 0x00020f94;
_DAT_0002187c = 0x0002187c;
DAT_00001022 = 0x00001022;
_DAT_0002070c = 0x0002070c;
DAT_00021ea0 = 0x00021ea0;
UNK_00003c39 = 0x00003c39;
DAT_00020346 = 0x00020346;
STR_010278a4 = 0x010278a4;
STR_0101bde8 = 0x0101bde8;
DAT_0102955b = 0x0102955b;
DAT_0002179a = 0x0002179a;
DAT_000206dd = 0x000206dd;
DAT_000201dc = 0x000201dc;
DAT_01028106 = 0x01028106;
STR_0101bc50 = 0x0101bc50;
DAT_000c804f = 0x000c804f;
_DAT_000206b6 = 0x000206b6;
_DAT_0002003c = 0x0002003c;
DAT_00020018 = 0x00020018;
_DAT_00020588 = 0x00020588;
DAT_000201b7 = 0x000201b7;
DAT_00020134 = 0x00020134;
_DAT_000201d8 = 0x000201d8;
DAT_000210a8 = 0x000210a8;
DAT_010294a8 = 0x010294a8;
STR_0101fe3c = 0x0101fe3c;
STR_01019f1c = 0x01019f1c;
STR_0102795a = 0x0102795a;
DAT_00020716 = 0x00020716;
_DAT_000200e4 = 0x000200e4;
DAT_0002030a = 0x0002030a;
UNK_0001d4c0 = 0x0001d4c0;
DAT_00021f82 = 0x00021f82;
DAT_000c8005 = 0x000c8005;
DAT_000f8808 = 0x000f8808;
DAT_01027a12 = 0x01027a12;
_DAT_e000e010 = 0xe000e010;
DAT_000f8523 = 0x000f8523;
STR_010296f0 = 0x010296f0;
_DAT_000f856c = 0x000f856c;
DAT_000f602a = 0x000f602a;
_DAT_00022ac2 = 0x00022ac2;
DAT_00021799 = 0x00021799;
DAT_00003ff9 = 0x00003ff9;
_DAT_00020014 = 0x00020014;
DAT_000f6001 = 0x000f6001;
_DAT_00020644 = 0x00020644;
STR_01022190 = 0x01022190;
STR_01018d0c = 0x01018d0c;
STR_01023d28 = 0x01023d28;
DAT_000215db = 0x000215db;
DAT_01027c0c = 0x01027c0c;
DAT_000217ec = 0x000217ec;
_DAT_000201ec = 0x000201ec;
_DAT_000206b8 = 0x000206b8;
DAT_000210ea = 0x000210ea;
_DAT_00020314 = 0x00020314;
STR_01027854 = 0x01027854;
STR_010278ec = 0x010278ec;
UNK_00008041 = 0x00008041;
STR_010201d8 = 0x010201d8;
STR_0101ff68 = 0x0101ff68;
STR_01029143 = 0x01029143;
STR_0101883c = 0x0101883c;
DAT_000206bc = 0x000206bc;
DAT_00020025 = 0x00020025;
DAT_00021eb8 = 0x00021eb8;
DAT_00020718 = 0x00020718;
DAT_0002058d = 0x0002058d;
DAT_000f6029 = 0x000f6029;
DAT_00020001 = 0x00020001;
_DAT_00021876 = 0x00021876;
DAT_000201b9 = 0x000201b9;
DAT_000206b2 = 0x000206b2;
DAT_0000ea60 = 0x0000ea60;
_DAT_00020120 = 0x00020120;
DAT_00021fc6 = 0x00021fc6;
_DAT_0002000c = 0x0002000c;
DAT_00001388 = 0x00001388;
_DAT_00020194 = 0x00020194;
_DAT_00020654 = 0x00020654;
STR_0101fee8 = 0x0101fee8;
DAT_010280fc = 0x010280fc;
DAT_00004680 = 0x00004680;
DAT_000f6010 = 0x000f6010;
DAT_0002179b = 0x0002179b;
DAT_00020038 = 0x00020038;
_DAT_00021920 = 0x00021920;
DAT_010282d2 = 0x010282d2;
DAT_00009018 = 0x00009018;
DAT_000c4fef = 0x000c4fef;
DAT_00020019 = 0x00020019;
DAT_0000157c = 0x0000157c;
DAT_00020638 = 0x00020638;
DAT_000f8810 = 0x000f8810;
DAT_00020133 = 0x00020133;
DAT_01029550 = 0x01029550;
DAT_0102966b = 0x0102966b;
DAT_0002070c = 0x0002070c;
STR_01022250 = 0x01022250;
DAT_01028953 = 0x01028953;
DAT_000201d1 = 0x000201d1;
DAT_00020715 = 0x00020715;
STR_0101fc08 = 0x0101fc08;
DAT_0002062e = 0x0002062e;
DAT_00021929 = 0x00021929;
DAT_01027a3b = 0x01027a3b;
DAT_00020784 = 0x00020784;
DAT_00020010 = 0x00020010;
_DAT_00020680 = 0x00020680;
_DAT_08003420 = 0x08003420;
_DAT_00020f98 = 0x00020f98;
STR_0101984c = 0x0101984c;
DAT_000c8022 = 0x000c8022;
DAT_00015f90 = 0x00015f90;
DAT_0002067f = 0x0002067f;
DAT_0002018d = 0x0002018d;
DAT_000f6000 = 0x000f6000;
DAT_000f880f = 0x000f880f;
DAT_000201cf = 0x000201cf;
DAT_01027c9b = 0x01027c9b;
STR_01027963 = 0x01027963;
_DAT_0002031c = 0x0002031c;
DAT_000f6027 = 0x000f6027;
DAT_00020775 = 0x00020775;
DAT_010279ee = 0x010279ee;
DAT_000215de = 0x000215de;
_DAT_00020622 = 0x00020622;
DAT_000f8800 = 0x000f8800;
_DAT_e000e018 = 0xe000e018;
_DAT_000206cc = 0x000206cc;
STR_01022260 = 0x01022260;
_DAT_0800341c = 0x0800341c;
STR_0101b570 = 0x0101b570;
DAT_00020024 = 0x00020024;
DAT_010180d0 = 0x010180d0;

      Parameter (MxMod=50)
      Character*72 Title
      Common / TitCom / Title
      Common / InfCom / EnEl (8), VibCon (36,MxMod), 
     #                  Freqs (MxMod), NEl, ISyEl (8), NElSy (8), 
     #                  NMod, LimQN (MxMod), NVibS, ISyMod (8), 
     #                  NModSy (8), ModBlo (8), NGroup, IToSym,
     #                  NSym, Indxx (MxMod), MemWd, NConf, NMatx, 
     #                  NQMax, NLanc, MulTab (8,8), 
     #                  ILTr (8,8), IntEl (8,8), NInt (8), MxLT,
     #                  NoSym

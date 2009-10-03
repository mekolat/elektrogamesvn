#ifndef _TMW_LANG_TR_H
#define _TMW_LANG_TR_H

#define CANTCREATEHOMEDIR " gerekli fakat olu�turulam�yor. ��k�l�yor!"
#define SDLINIT "SDL ba�lat�l�yor..."
#define SDLCANTINIT "SDL ba�lat�lam�yor : "
#define CANTSETHOME " ana dizin ayarlanam�yor. ��k�l�yor!"
#define CANTSETUPDATES " dizini olu�turulam�yor. ��k�l�yor!"
#define CANTFINDRESOURCE " kaynak klas�r� bulunam�yor.\n"
#define INITCONFIG "Ayarlamalar ba�l�yor..."
#define CANTCRATECONFIGPATH configPath << "olu�turulamad� " << ". Varsay�lan ayarlar kullan�l�yor."
#define VIDEOMODEERR "x: " << width << "Y:" << height << "��z�n�rl�k" << bpp << " olarak ayarlanamad� "
#define WARNINGS "Dikkat: %s"
#define HS0 "tmw" << std::endl << std::endl
#define HS1         << "Options: " << std::endl
#define HS2         << "  -h --help       : Display this help" << std::endl
#define HS3         << "  -v --version    : Display the version" << std::endl
#define HS4         << "  -u --skipupdate : Skip the update process" << std::endl
#define HS5         << "  -U --username   : Login with this username" << std::endl
#define HS6         << "  -P --password   : Login with this password" << std::endl
#define HS7         << "  -D --default    : Bypass the login process with default settings" << std::endl
#define HS8         << "  -p --playername : Login with this player" << std::endl
#define HS9         << "  -C --configfile : Configuration file to use"
#define HELPSCREEN HS0 HS1 HS2 HS3 HS4 HS5 HS6 HS7 HS8 HS9
#define TMWVERSION "ElektroGame versiyon "
#define TRYACCSERV "Hesap sunucusuna ba�lanmay� deniyor..."
#define USERNAMES "Kullan�c� adi: %s"
#define TRYCHARSERV "Karakter sunucusuna ba�lanmay� deniyor..."
#define MEMOCHAR "Se�ilen karakter %s"
#define TRYMAPSERV "MAP sunucuna ba�lanmay� deniyor..."
#define MAPS "Harita: %s"
#define DISCONNECT "Sunucuyla ba�lant� kesildi!"
#define STATELOADDATA "Durum: Data y�kleme."
#define STATELOGIN "Durum: LOGIN"
#define STATEREGISTER "Durum: REGISTER"
#define STATECHARSERVER "Durum: CHAR_SERVER"
#define STATECHARSELECT "Durum: CHAR_SELECT"
#define STATEGAME "Durum: GAME"
#define STATEUPDATE "Durum: UPDATE"
#define STATEERROR "Durum: ERROR"
#define ERROR "Hata"
#define STATECONNECT "Durum: CONNECTING"
#define CONNECTMAP "Map sunucusuna ba�lan�yor..."
#define CONNECTCHAR "Karakter sunucusuna ba�lan�yor..."
#define CONNECTACCOUNT "Hesap sunucusuna ba�lan�yor..."
#define STATEEXIT "State: EXIT"
#define NOCONFIGFILE "Uyar�: Config dosyas� bulunamad� (%s)"
#define CONFOPENERR "Configuration::write() %s dosyas� yazma i�in ac�lamad�."
#define CONFCREATEERR "Configuration::write() yazma amac�yla olu�turulamad�."
#define CONFWRITE "Configuration::write() ayarlar yaz�l�yor..."
#define SCREENSAVE "Ekran�n g�r�nt�s� kaydedildi:"
#define SCREENSAVEERR "Ekran g�r�nt�s� kaydedilemedi!"
#define SUREQUIT "Oyundan ��kmak istedi�inize emin misiniz?"
#define QUIT "��k��"
#define GUICHANERR "Dikkat: guichan hata �retti: %s"
#define SETVIDEOMODE "Ekran modu ayarland�: %dx%d %s",w, h, fs ? "Tam ekran" : "Pencere"
#define USEVIDEODRVS "Kullan�lan ekran sunucusu: %s"
#define USEVIDEODRVNON "Kullan�lan ekran s�r�c�s�: bilinmiyor"
#define VIHWAVAILABLE "Possible to create hardware surfaces: %s",((vi->hw_available) ? "evet" : "hay�r")
#define VIVMAVAILABLE "Window manager available: %s",((vi->wm_available) ? "evet" : "hay�r")
#define VIBLITHW "Accelerated hardware to hardware blits: %s",((vi->blit_hw) ? "evet" : "hay�r")
#define VIBLITHWCC "Accelerated hardware to hardware colorkey blits: %s", ((vi->blit_hw_CC) ? "evet" : "hay�r")
#define VIBLITHWA "Accelerated hardware to hardware alpha blits: %s",((vi->blit_hw_A) ? "evet" : "hay�r")
#define VILITSW "Accelerated software to hardware blits: %s",((vi->blit_sw) ? "yes" : "no")
#define VIBLITSWCC "Accelerated software to hardware colorkey blits: %s",((vi->blit_sw_CC) ? "yes" : "no")
#define VIBLITSWA "Accelerated software to hardware alpha blits: %s",((vi->blit_sw_A) ? "yes" : "no")
#define VIBLITFILL "Accelerated color fills: %s",((vi->blit_fill) ? "yes" : "no")
#define VIVIDEOMEM "Available video memory: %d", vi->video_mem
#define LOGOPENERR "Dikkat :" << logFilename <<" dosyas� a��l�rken hata olu�tu.\n"
#define BTNOK "Tamam"
#define BTNCANCEL "�ptal"
#define BTNYES "Evet"
#define BTNNO "Hay�r"
#define BTNCLOSE "Kapat"
#define CONFIRM "ONAY"
#define DELETECHAR "Bu karakteri silmek istedi�inize emin misiniz?"
#define BTNNEW "Yeni"
#define BTNDELETE "Sil"
#define BTNPREV "�nceki"
#define BTNNEXT "Sonraki"
#define LBLNAME "�sim"
#define LBLLEVEL "Seviye"
#define LBLJOBL "G�rev Sev"
#define LBLMONEY "Para"
#define LBLJOBL2 "Job Level: "
#define LBLMONEY2 "Gold: "
#define LBLNAME2 "�sim: "
#define CREATECHAR "Karakter Olu�turma"
#define HAIRCOLOR "Sac Rengi:"
#define HAIRSTYLE "Sac Stili:"
#define BTNCREATE "Olu�tur"
#define NAME4CHAR "�sim en az 4 karakter olmal�."
#define LBLPASS2 "Parola:"
#define LBLSERVER2 "Sunucu:"
#define BTNREGISTER "Kaydet"
#define LBLCONFIRM2 "Kontrol:"
#define BTNMALE "Erkek"
#define BTNFEMALE "K�z"
#define ERRSHORTUSERNAME "Kullan�c� adi en az " << LEN_MIN_USERNAME << " uzunlu�unda olmal�."
#define ERRLONGUSERNAME "Kullan�c� adi en fazla " << LEN_MAX_USERNAME << " karakter olabilir."
#define ERRSHORTPASS "Parola en az " << LEN_MIN_PASSWORD << " uzunlu�unda olmal�."
#define ERRLONGPASS "Parola en fazla " << LEN_MAX_PASSWORD << " karakter olabilir."
#define ERRPASSMATCH "Parolalar tutars�z."
#define LBLCONNECTING "Ba�lan�yor..."
#define BTNPLAY "Oyna"
#define LBLCOMPLETED "Tamamland�"
#define ERRACCESSDENIED "Eri�im Engellendi"
#define ERRNONID "Bu hesap kullan�lm�yor"
#define ERRUNKNOWN "Karakter se�iminde bilinmeyen hata"
#define ERRNAMEALREADDY "Karakter olu�turmada hata. Bu isim daha �nceden al�nm��."
#define INFO "Bilgi"
#define PLAYERDELETED "Oyuncu silindi"
#define PlAYERCANTDELETE "Karakter silinemedi."
#define MAPSERVEROFF "Harita sunucu kapal�"
#define SPEEDHACK "H�z hack tespit edildi"
#define DUPLICATEDLOGIN "�kinci giri�"
#define UNKNOWN081 "Bilinmeyen hata: 0x0081"
#define UNREGISTEREDID "Kay�tl� olmayan ID"
#define WRONGPASS "Yanl�� Parola"
#define ACCOUNTEXPIRED "Hesap suresi doldu"
#define REJECTEDSERVER "Sunucu taraf�ndan reddedildiniz"
#define YOUBLOCKED "Y�neticiler taraf�ndan bloke edildiniz"
#define YOUBANNED "5 dakikal�k giril yasa��"
#define NAMEALREADYTAKEN "Bu isimde kullan�c� zaten mevcut"
#define UNKNOWNERR "Bilinmeyen hata"
#define LBLPRICE "�cret: 0 GP / 0 GP"
#define BTNBUY "Sat�n al"
#define LBLDESC2 "A��klama :"
#define LBLDESC "A��klama"
#define LBLEFFECT2 "Etki :"
#define LBLEFFECT "Etki"

#define UPDATING "G�ncelleniyor..."
#define BUY "Sat�n Al"
#define PRICEGP "�cret: 0 GP / " + toString(mMoney)  + " GP"
#define PRICEGP2 "�cret: " + toString(price)  + " GP / " \
                                + toString(mMoney) + " GP"
#define SHOP "D�kkan"
#define BTNSELL "sat"
#define SELECTCHARACTER "Karakter Se�"
#define SELECTSERVER "Sunucu Se�"
#define CHATLOGHELP "-- Yard�m --"
#define CHATLOG1 "/help : Yard�mc� ekran�n� g�ster."
#define CHATLOG2 "/announce : Genel duyuru (sadece y�neticiler)"
#define CHATLOG3 "/where : Harita ismini g�ster"
#define CHATLOG4 "/who : �evrimi�i oyuncu say�s�n� g�ster"
#define CHATLOGUN "Bilinmeyen komut"

#define MSGBSKILL_TRADE "Al��veri� olmad�!"
#define MSGBSKILL_EMOTE "Duygu g�sterilemedi!"
#define MSGBSKILL_SIT "Oturma ger�ekle�emedi!"
#define MSGBSKILL_CREATECHAT "Sohbet yap�lamad�!"
#define MSGBSKILL_JOINPARTY "Partiye kat�lamad�n�z!"
#define MSGBSKILL_SHOUT "Ba��ramazs�n�z!"
#define MSGRFAIL_SKILLDEP " Hen�z yeterli seviyeye gelmediniz!"
#define MSGRFAIL_INSUFHP " Insufficient HP!"
#define MSGRFAIL_INSUFSP " Insufficient SP!"
#define MSGRFAIL_NOMEMO " You have no memos!"
#define MSGRFAIL_SKILLDELAY " Bunu simdi yapamazsiniz!"
#define MSGRFAIL_ZENY " Seems you need more Zeny... ;-)"
#define MSGRFAIL_WEAPON " You cannot use this skill with that kind of weapon!"
#define MSGRFAIL_REDGEM " You need another red gem!"
#define MSGRFAIL_BLUEGEM " You need another blue gem!"
#define MSGRFAIL_OVERWEIGHT " You're carrying to much to do this!"
#define MSGDEF " Huh? What's that?"
#define MSGSKILL_WARP "Warp failed..."
#define MSGSKILL_STEAL "Could not steal anything..."
#define MSGSKILL_ENVENOM "Poison had no effect..."

#define DEBUG "Hata Gider"
#define DBGMUSICFILE "M�zik Dosyas�: "
#define DBGMINIMAP "K���k harita : "
#define DBGPARTICLE "[Par�ac�k Say�s�: 0]"
#define EQUIPMENT "Ekipman"
#define HELP "Yard�m"
#define INVENTORY "Aletler"
#define BTNUSE "Kullan"
#define BTNDROPE "B�rak"
#define TOTALMAXWEIGHT "Toplam A��rl�k: - Maksimum A��rl�k: "
#define TOTALWEIGHT "Toplam A��rl�k: "
#define MAXWEIGHT "Maksimum A��rl�k: "
#define SELECTAMOUNTITEMDROP "B�rak�lacak item miktar�n� belirtin."
#define SELECTAMOUNTITEMTRADE "Al��veri�te kullan�lacak item miktar�n� belirtin."
#define LOGIN "Giri�"
#define MINIMAP "K���k Harita"
#define LBLNPC "�stat"
#define MONEYTOTAL "Para: 0 GP / Toplam: 0 GP"
#define MONEYPLAYER "Para: 0 GP / Toplam: "+ toString(mPlayerMoney) + " GP"
#define MONEYPLAYER2 "Para: " + toString(price) + " GP / Toplam: " + toString(price + mPlayerMoney) + " GP"
#define LBLSETUP "Ayar"
#define BTNAPPLY "Uygula"
#define BTNRESETWINDOWS "S�f�rla"
#define LBLVIDEO "G�r�nt�"
#define LBLAUDIO "Ses"
#define LBLJOYSTICK "Joystick"
#define LBLSFXVOLUME "Efekt sesi"
#define LBLMUSICVOLUME "M�zik sesi"
#define LBLSOUND "Ses A��k"
#define LBLSTARTCALIB "Kalibrasyonu ba�latmak i�in d��meye bas�n."
#define BTNCALIBRATE "Kalibrasyon"
#define LBLANABLEJOYSTICK " Joystick A��k"
#define LBLSTOP "Stop"
#define LBLROTATESTICK " Joystick dondurun"
#define LBLFULLSCREEN "Tam Ekran"
#define LBLCUSTOMCURSOR "�zel �mle�"
#define LBLFPSLIMIT2 "FPS Limiti: "
#define LBLSCROLLLAZINESS "Kayma yava�l���"
#define LBLGUIOPACITY "�effafl�k"
#define LBLSCROLLRADIUS "Kayma �ap�"
#define LBLAMBIENTFX "Cevre Efekt"
#define LBLOFF "kapal�"
#define LBLLOW "d���k"
#define LBLHIGH "y�ksek"
#define LBLSKILLS "Huner"
#define LBLSKILLPOINT2 "Huner Puan�:"
#define LBLSKILLPOINT2i "Huner Puan�: %i"
#define BTNUP "Art"
#define BTNUSE "Kullan"
#define LBLLEVEL2 "Seviye:"
#define LBLMONEY22 "Para:"
#define LBLSTATUS "Durum"
#define LBLHP2 "SP:"
#define LBLEXP2 "Tecr�be:"
#define LBLMP2 "Enerji Seviyesi:"
#define LBLJOB2 "Uzmanl�k:"
#define LBLSTATS "�statistikler"
#define LBLTOTAL "Total"
#define LBLCOST "�cret"
#define LBLATTACK "Atak:"
#define LBLDEFENSE "Savunma:"
#define LBLMATTACK "Genel Yetenek:"
#define LBLMDEFENSE "K�lt�r:"
#define LBLACCURACY "Teknik:"
#define LBLEVADE "Tecr�be:"
#define LBLREFLEX "Uzmanl�k:"
#define LBLREMAININGSTATUS "Kalan durum puan�: "
#define LBLSTRENGTH "G��"
#define LBLAGILITY "�eviklik"
#define LBLVITALITY "Dayan�kl�l�k"
#define LBLINTELLIGENCE "Zeka"
#define LBLDEXTERITY "Ustal�k"
#define LBLLUCK "�ans"
#define LBLTRADEYOU "Alisveris"
#define BTNADD "Ekle"
#define BTNTRADE "Al Sat"
#define LBLYOUGET "Ald�n: 0z"
#define LBLYOUGET2 "Ald�n:"
#define LBLYOUGIVE "Verdin:"
#define FAILEDADDING "Eleman eklenemedi. Pencere bir tane daha ekleyemezsin."
#define BTNCHECK "Kontrol Et"
#define BTNREMOVE "Kald�r"
#define LBLCALCULATOR "Hesap Mak."


#endif

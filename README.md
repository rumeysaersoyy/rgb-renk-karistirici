# Arduino RGB LED Renk Karıştırıcı

Elinde bir joystick, bir potansiyometre ve biraz sabırsızlık varsa, bu proje tam sana göre. Joystick'i oynat, potansiyometreyi çevir, LED'in rengini gökkuşağının her tonuna sür — hepsi gerçek zamanlı, hepsi senin elinde.

- **Joystick X ekseni** → Kırmızı (sağa kaydır, kıpkırmızı kesil)
- **Joystick Y ekseni** → Yeşil (yukarı it, zehir yeşili yap)
- **Potansiyometre** → Mavi (çevir dur, mavinin tüm tonlarını gez)

Üçünü aynı anda oynatırsan teorik olarak 16 milyondan fazla renk çıkar ortaya — pratikte çoğu zaman garip bir mor-pembe karışımı elde edersin ama o da güzel. İşin özünde `analogRead` ile analog girişleri okumak, `analogWrite` ile de PWM çıkışı üretmek var. Yani hem eğlenceli hem öğretici, nadir bulunan bir kombinasyon.

## Gerekli parçalar

| Parça | Adet |
|---|---|
| Arduino Mega 2560 veya Uno (klon da olur, kimse sormaz) | 1 |
| RGB LED modülü (ortak katot, kart üzerinde direnci hazır) | 1 |
| XY joystick modülü | 1 |
| 10K potansiyometre | 1 |
| Breadboard | 1 |
| Jumper kablolar (erkek-erkek, dişi-erkek) | ~15 |
| USB kablosu (veri destekli — şarj kablosuyla uğraşıp durma) | 1 |

Bu proje "Kids Maker 220 Parça Süper Başlangıç Seti" ile yapıldı. Yani çocuklar bile yapabiliyor, senin de yapabileceğinden eminiz.

## Bağlantılar

**RGB LED modülü**

| Modül pini | Arduino |
|---|---|
| `-` (GND) | GND |
| `R` | 9 |
| `G` | 10 |
| `B` | 11 |

**Joystick**

| Joystick pini | Bağlantı |
|---|---|
| GND | GND (breadboard `-` rayı) |
| +5V | 5V (breadboard `+` rayı) |
| VRx | A0 |
| VRy | A1 |
| SW | boş (basma tuşuna bu projede iş yok, kendi başının çaresine baksın) |

**Potansiyometre**

| Bacak | Bağlantı |
|---|---|
| Sol | 5V (`+` rayı) |
| Orta | A2 |
| Sağ | GND (`-` rayı) |

> Kablo bağlantılarını **USB takılı değilken** yap. 5V ve GND hatlarının birbirine değmediğinden emin ol — kısa devre hem kartını hem bilgisayarının portunu üzer, kimse üzülmesin.

## Kurulum

1. [Arduino IDE](https://www.arduino.cc/en/software) kur.
2. `rgb_renk_karistirici/rgb_renk_karistirici.ino` dosyasını aç.
3. **Tools > Board** menüsünden kartını seç (Mega 2560 veya Uno), **Tools > Port** menüsünden portu seç.
4. **Upload** tuşuna bas ve LED'in canlanmasını izle.

## Sorun giderme

- **Port görünmüyor / yükleme hatası:** Veri destekli USB kablosu kullan, klon kartlar bazen CH340 sürücüsü ister, onu kur.
- **LED hiç yanmıyor:** Modülde `-` yerine `+` yazıyorsa ortak anottur; o pini 5V'a bağla ve koddaki değerleri `255 - değer` yap. (Evet, LED'ler de bazen ters giyinir.)
- **Renkler karışık:** R/G/B kablolarının sırasını ya da koddaki pin numaralarını değiştir.
- **Bir eksen ters çalışıyor:** İlgili `map` satırında `0, 255` yerine `255, 0` yaz.
- **Ethernet shield takılıysa:** Shield 10, 11, 12, 13 pinlerini kullanır; shield'i çıkar ya da LED'i başka PWM pinlerine taşı.

## Geliştirme fikirleri

- LCD ekranda anlık RGB değerlerini göstermek (teknik görünmek isteyenler için şart)
- IR kumanda ile hazır renkler seçmek (kalkmadan renk değiştirme lüksü)
- Seri port üzerinden bilgisayardan renk komutu göndermek
- Müziğe göre renk değiştiren bir mod (bonus puan, ama uğraşması gerçek)

## Lisans

MIT — kopyala, çoğalt, geliştir, sadece bir yerde ismimizi bırak.

# Arduino RGB LED Renk Karıştırıcı

Joystick ve potansiyometre ile RGB LED'in rengini gerçek zamanlı ayarlayan basit bir Arduino projesi.

- **Joystick X ekseni** → Kırmızı
- **Joystick Y ekseni** → Yeşil
- **Potansiyometre** → Mavi

Üç kanalın karışımı sayesinde 16 milyondan fazla farklı renk elde edilir. Arduino'nun `analogRead` ile analog giriş okuma ve `analogWrite` ile PWM çıkışı üretme mantığını öğrenmek için uygundur.

## Gerekli parçalar

| Parça | Adet |
|---|---|
| Arduino Mega 2560 veya Uno (klon da olur) | 1 |
| RGB LED modülü (ortak katot, kart üzerinde direnci hazır) | 1 |
| XY joystick modülü | 1 |
| 10K potansiyometre | 1 |
| Breadboard | 1 |
| Jumper kablolar (erkek-erkek, dişi-erkek) | ~15 |
| USB kablosu (veri destekli) | 1 |

Proje, "Kids Maker 220 Parça Süper Başlangıç Seti" ile yapılmıştır.

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
| SW | boş |

**Potansiyometre**

| Bacak | Bağlantı |
|---|---|
| Sol | 5V (`+` rayı) |
| Orta | A2 |
| Sağ | GND (`-` rayı) |

> Kablo bağlantılarını **USB takılı değilken** yap. 5V ve GND hatlarının birbirine değmediğinden emin ol (kısa devre kartı ve bilgisayar portunu bozabilir).

## Kurulum

1. [Arduino IDE](https://www.arduino.cc/en/software) kur.
2. `rgb_renk_karistirici/rgb_renk_karistirici.ino` dosyasını aç.
3. **Tools > Board** menüsünden kartını seç (Mega 2560 veya Uno), **Tools > Port** menüsünden portu seç.
4. **Upload** tuşuna bas.

## Sorun giderme

- **Port görünmüyor / yükleme hatası:** Veri destekli USB kablosu kullan, gerekirse klon kartlar için CH340 sürücüsünü kur.
- **LED hiç yanmıyor:** Modülde `-` yerine `+` yazıyorsa ortak anottur; o pini 5V'a bağla ve koddaki değerleri `255 - değer` yap.
- **Renkler karışık:** R/G/B kablolarının sırasını ya da koddaki pin numaralarını değiştir.
- **Bir eksen ters çalışıyor:** İlgili `map` satırında `0, 255` yerine `255, 0` yaz.
- **Ethernet shield takılıysa:** Shield 10, 11, 12, 13 pinlerini kullanır; shield'i çıkar ya da LED'i başka PWM pinlerine bağla.

## Geliştirme fikirleri

- LCD ekranda anlık RGB değerlerini göstermek
- IR kumanda ile hazır renkler seçmek
- Seri port üzerinden bilgisayardan renk komutu göndermek

## Lisans

MIT

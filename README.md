# biasceptive
An arduino project to raise awareness of the gender data gap.

## Why?
Since the 1870s, women* had to fight for their right of birth control [(Gordon 2002)](#gordon_2002). Luckily, a lot has changed since then and women* can choose from a variety of contraceptives. This choice comes at a cost, though. Since the beginning of the 20th century, when women* became subject of scientific research through the developments of gynaecology and endocrinology, a gendering of contraceptives took place [(Klemm 2016)](#klemm_2016). As a consequence, the majority of contraceptives for women* emerged in the past century. In contrast, the research of contraceptives for men* stagnated [(Lloyd and Waterfield2016)](#lloyd_2016). This lead to a discrepancy in the contraceptive availability of 16:2, where 16 contraceptives are available for women* but only 2 for men* (with the vasectomy being one of it).

## What?
Following a Critical Making process (cf. [(Ratto 2011)](#ratto_2011)), we created a critical artifact we call _Verhütomat_ (Contraceptomat):

![Image of the Verhütomat](verhuetomat.jpg)

The _Verhütomat_ lists both female* (front) and male* (back) contraceptives. It uses two servos to indicate the currently selected contraceptives. In the inside, it is driven by an arduino board, connected to the servos and to a ultra sonic sensor. If the sensor detects a movement, the servos are started and will randomly show one contraceptive each (on one side for women* and for men* on the other side).

## References
<span class="anchor" id="gordon_2002">Gordon, Linda. 2002.</span> _''The Moral Property of Women: A History of Birth Control Politics in America''_. [University of Illinois Press](https://www.jstor.org/stable/10.5406/j.ctt3fh3j5)

<span class="anchor" id="klemm_2016">Klemm, Miriam. 2016.</span> _''Keine Pille für den Mann - Vergeschlechtlichung in der Entwicklung von Kontrazeptiva''_. [Powision - Differenzen, No. 18: pp. 65–68](https://www.academia.edu/29142662/Keine_Pille_f%C3%BCr_den_Mann_Vergeschlechtlichung_in_der_Entwicklung_von_Kontrazeptiva)

<span class="anchor" id="lloyd_2016">Lloyd, Alison and Jackie Waterfield. 2016.</span> _''Men’s perspectives of male hormonal contraception''_. International Journal of Reproduction,
Contraception, Obstetrics and Gynecology: pp. 2546–2552.

<span class="anchor" id="ratto_2011">Ratto, Matt. 2011.</span> _''Critical Making: Conceptual and Material Studies in Technology and Social Life''_. [The Information Society 27](https://www.researchgate.net/publication/220175067_Critical_Making_Conceptual_and_Material_Studies_in_Technology_and_Social_Life#fullTextFileContent) (4): pp. 252–260.

**************ЗАКРОЙ ЭТО ОКОШКО ПЕРЕД ТЕМ КАК РАБОТАТЬ С ПРОГРАММОЙ**********
Привет, собрал первый черновичок курсовой. Прошу Помочь мне с тестированием!
в текущем каталоге можно создавать .txt файлы с входными значениями вида
квадратная матрица нулей и единиц (без пробелов), где единицы образуют неразрывную линию
по типу 
00001
00011
00100
10100
11100
Причем первая единица (хвост или голова "змейки" расположена на нулевом столбце)

единицы не могут образовывать такую группу:
......
.0010.
.0011.
.0011.
.0000.
...... то есть линия единиц должна задаваться однозначно, без разночтений. Иначе прога рухнет, ибо алгоримт поиска многократно усложнится (надеюсь, ТЗ это предусматривает, иначе придется оч сильно мудрить)

После создания файлов с тестами, нужно включить его название в блок switch в функции swither (main.cpp). 
Буду благодарен, если вы облагородите вывод и припилите строки вывода, для отладки.
Если что то отваливается, напишите. Можете создать ветку на Гите и подправить. Посмотрим вместе. 
В main->switcher->(блок свитч)

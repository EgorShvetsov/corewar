# corewar
Проект сorewar, выполненный в рамках обучения в школе 21, представляет собой интерпретацию игры ["Core War"](https://ru.wikipedia.org/wiki/%D0%91%D0%BE%D0%B9_%D0%B2_%D0%BF%D0%B0%D0%BC%D1%8F%D1%82%D0%B8). Реализованы транслятор ассемблера в байт код и виртуальная машина.

## Установка
```
git clone https://github.com/EgorShvetsov/corewar.git <dir_name>
cd <dir_name>
make
```
Для корректной компиляции под Linux может потребоваться заменить компилятор с gcc на clang в строке 5 asm_dir/Makefile и в строке 145 vm_dir/Makefile.

## Запуск
Для трансляции файла с кодом чемпиона в байт код:
```
./asm <champion_name>.s
```
Примеры чемпионов лежат в дирректории champs.

Для запуска виртуальной машины:
```
./corewar <champ_1>.cor <champ_2>.cor
```


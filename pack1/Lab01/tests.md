# 1a. Кратные числа
./main.out 7 -h
./main.out 13 -h
./main.out 25 -h
./main.out 101 -h  # нет кратных
./main.out 1 -h    # все числа от 1 до 100

# 1b. Простые числа
./main.out 2 -p     # простое
./main.out 17 -p    # простое
./main.out 15 -p    # составное
./main.out 1 -p     # не простое и не составное
./main.out 97 -p    # простое (максимальное < 100)

# 1c. 16-ричные цифры
./main.out 255 -s      # FF
./main.out 4096 -s     # 1000
./main.out 123456 -s   # 1E240
./main.out 15 -s       # F
./main.out 0 -s        # 0

# 1d. Таблица степеней (x ≤ 10)
./main.out 1 -e
./main.out 5 -e
./main.out 10 -e
./main.out 3 -e

# 1e. Сумма натуральных чисел
./main.out 1 -a     # 1
./main.out 10 -a    # 55
./main.out 100 -a   # 5050
./main.out 1000 -a

# 1f. Факториал
./main.out 0 -f     # 1
./main.out 1 -f     # 1
./main.out 5 -f     # 120
./main.out 10 -f    # 3628800

# Неправильное количество аргументов
./main.out
./main.out 5
./main.out -h
./main.out 5 -h extra_arg
./main.out 5 -h 10

# Неправильные флаги
./main.out 5 -x
./main.out 5 -help
./main.out 5 /h
./main.out 5 --h
./main.out 5 -H

# Некорректные числа
./main.out abc -h
./main.out -5 -a
./main.out 3.14 -p
./main.out 999999999999999999 -f

# Нарушение ограничений
./main.out 11 -e    # x > 10 для флага -e
./main.out 0 -e     # x < 1 для флага -e
./main.out -1 -a    # отрицательное для -a
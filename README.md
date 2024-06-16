# swo-debug
Библиотека для вывода данных в терминал при работе с stm32 через интерфейс SWD. Используется опциональный сигнал **S**erial **W**ire **O**utput (SWO) из SWD.
## Требования
- С++11 или выше
## Поддерживаемые типы данных
### Поддерживаемые типы данных:
- Целочисленные данные (uint8_t, int8_t, uint16_t, int16_t(int) и т.д.)
- Строки (std::string)
- Символы (char и т.д.)
- Логический тип (bool)
- Вектора с целочисленными данными (std::vector<int> и т.д.)
- Вектора со строками (std::vector<int> и т.д.)

### Неподдерживаемые типы данных:
- Числа с плавающей точкой (float, double)
- Любые типы, которые не указаны выше

## Пример использования
```c++
#include "debug.hpp"
```
```c++
std::vector<int> vec_int = {1, 2, 3, 4, 5};
swoTerminal << "Vector<int>: " << vec_int << std::endl;

std::vector<std::string> vec_str = {"1a", "2b", "3c", "4d", "5e"};
swoTerminal << "Vector<string>: " << vec_str << std::endl;

uint8_t b = 2;
swoTerminal << "uint8_t: " << b << std::endl;

int8_t c = -5;
swoTerminal << "int8_t: " << c << std::endl;

uint16_t d = 65535;
swoTerminal << "uint16_t: " << d << std::endl;

int16_t e = -32768;
swoTerminal << "int16_t: " << e << std::endl;

uint32_t f = 4294967295U;
swoTerminal << "uint32_t: " << f << std::endl;

int32_t g = -2147483648;
swoTerminal << "int32_t: " << g << std::endl;

uint64_t h = 18446744073709551615ULL;
swoTerminal << "uint64_t: " << h << std::endl;

int64_t i = -9223372036854775807LL - 1;
swoTerminal << "int64_t: " << i << std::endl;
```
Вывод в терминал
```
Vector<int>: [1, 2, 3, 4, 5]
Vector<string>: [1a, 2b, 3c, 4d, 5e]
uint8_t: 2
int8_t: -5
uint16_t: 65535
int16_t: -32768
uint32_t: 4294967295
int32_t: -2147483648
uint64_t: 18446744073709551615
int64_t: -9223372036854775808
```

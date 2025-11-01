
# Capítulo 1: Plantillas de Función

Este capítulo introduce las **plantillas de función** en C++, una herramienta poderosa para escribir funciones genéricas que funcionan con múltiples tipos.

---

## 1.1 Primer vistazo a las plantillas de función

Las plantillas de función permiten definir un **comportamiento funcional** que puede aplicarse a **diferentes tipos**. Una plantilla representa una **familia de funciones**.

### 1.1.1 Definición de la plantilla

Ejemplo básico: función `max()` que devuelve el mayor de dos valores.

```cpp
// basics/max1.hpp
template<typename T>
T max(T a, T b)
{
    return b < a ? a : b;  // Nota: orden intencional por razones de equivalencia
}

- `template<typename T>` declara un **parámetro de tipo** `T`.
- `< >` son **corchetes angulares**.
- `typename` introduce un parámetro de tipo (también se permite `class`, pero `typename` es preferido por claridad).
- `T` debe soportar:
    - `operator <` (para la comparación)
    - Ser **copiable** (para devolver valores) → desde C++17, se permiten temporales incluso sin constructor de copia/movimiento válido.

> **Nota histórica**: `class` era la única opción antes de C++98. Hoy ambas son válidas, pero `typename` es más claro.

---

### 1.1.2 Uso de la plantilla

```cpp
// basics/max1.cpp
#include "max1.hpp"
#include <iostream>
#include <string>

int main()
{
    int i = 42;
    std::cout << "max(7,i): " << ::max(7, i) << '\n';

    double f1 = 3.4, f2 = -6.7;
    std::cout << "max(f1,f2): " << ::max(f1, f2) << '\n';

    std::string s1 = "mathematics", s2 = "math";
    std::cout << "max(s1,s2): " << ::max(s1, s2) << '\n';
}
```

**Salida:**
```
max(7,i): 42
max(f1,f2): 3.4
max(s1,s2): mathematics
```

- Se usa `::max` para evitar conflictos con `std::max`.
- Cada llamada **instancia** la plantilla con un tipo concreto (`int`, `double`, `std::string`).
- El compilador genera una función especializada por tipo.

---

### Instantación

Las plantillas **no se compilan una sola vez**. Por cada tipo usado, se genera una **instancia**:

```cpp
int max(int, int);        // para int
double max(double, double); // para double
```

> Proceso: **reemplazo de parámetros → instanciación → generación de código**.

---

### 1.1.3 Traducción en dos fases

Los compiladores verifican plantillas en **dos etapas**:

| Fase | Qué se verifica |
|------|-----------------|
| **1. Definición** (sin instanciar) | Errores de sintaxis, nombres desconocidos no dependientes de `T`, `static_assert` independientes |
| **2. Instanciación** | Todo el código con `T` sustituido → errores si `T` no soporta las operaciones |

```cpp
template<typename T>
void foo(T t)
{
    undeclared();        // Error en fase 1 si no existe
    undeclared(t);       // Error en fase 2 si no existe para T
    static_assert(sizeof(T) > 10, "T too small"); // Fase 2
}
```

> **Consejo**: Algunos compiladores (como versiones antiguas de Visual C++) no hacen todas las comprobaciones en fase 1.

---

## Compilación y enlazado

- Para usar una plantilla, el compilador **debe ver su definición** (no solo declaración).
- **Solución práctica**: Definir plantillas en **archivos de cabecera** (`.hpp` o `.h`).

---

## 1.2 Deducción de argumentos de plantilla

El compilador **deduce automáticamente** el tipo `T` a partir de los argumentos.

```cpp
template<typename T>
T max(T const& a, T const& b);

max(7, 42);     // T → int
max(3.14, 2.71); // T → double
```

### Conversiones permitidas en deducción

| Por referencia (`T const&`) | Por valor (`T`) |
|---------------------------|-----------------|
| **Solo coincidencia exacta** | Se permiten conversiones triviales: <br> • `const`/`volatile` ignorados <br> • Arrays → punteros <br> • Funciones → punteros |

#### Ejemplos válidos (por valor):
```cpp
int const c = 42;
max(i, c);     // OK → T = int
int arr[4];
max(&i, arr);  // OK → T = int*
```

#### Errores comunes:
```cpp
max(4, 7.2);         // ERROR: T no puede ser int y double a la vez
max("hello", s);     // ERROR: char[6] vs std::string
```

### Soluciones:
1. **Conversión explícita**:
   ```cpp
   max(static_cast<double>(4), 7.2);
   ```
2. **Especificar tipo explícitamente**:
   ```cpp
   max<double>(4, 7.2);
   ```
3. **Permitir tipos diferentes** → ver sección 1.3

---

## 1.3 Parámetros de plantilla múltiples

Pronto veremos cómo permitir tipos distintos en los argumentos.

---

## 1.4 Argumentos por defecto en plantillas

La deducción **no funciona** con argumentos por defecto en llamadas:

```cpp
template<typename T>
void f(T = "");  // Error: no se puede deducir T en f()

f(1);  // OK → T = int
f();   // ERROR
```

**Solución**: Default en el parámetro de plantilla:

```cpp
template<typename T = std::string>
void f(T = "");

f();  // OK → T = std::string
```

---

## Resumen clave

| Concepto | Detalle |
|--------|--------|
| `template<typename T>` | Declara parámetro de tipo |
| Instanciación | Genera función por cada tipo usado |
| Dos fases | Comprobación sin/con parámetros |
| Deducción | Automática, con reglas estrictas |
| Archivos | Definiciones en `.hpp` |
| `::max` | Evita conflicto con `std::max` |

---

> **Siguiente**: [Capítulo 2 - Plantillas de clase →](#)
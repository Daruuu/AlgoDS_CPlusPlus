
## 1.3 Parámetros de plantilla múltiples

Cuando los argumentos de una llamada no permiten deducir **todos** los parámetros de plantilla, debes especificarlos **explícitamente**.

---

### 1.3.1 Parámetros de plantilla para el tipo de retorno

La **deducción de argumentos de plantilla** no considera el **tipo de retorno**. Por tanto, si un parámetro de plantilla solo aparece en el retorno, **no puede deducirse**.

#### Ejemplo con tipo de retorno explícito:

```cpp
template<typename T1, typename T2, typename RT>
T1 max (T1 a, T2 b)
{
    return b < a ? a : b;
}

::max<int, double, double>(4, 7.2);  // OK, pero tedioso
```

> **Problema**: `RT` no aparece en los parámetros → **no se deduce**.

#### Solución: Reordenar parámetros

```cpp
template<typename RT, typename T1, typename T2>
RT max(T1 a, T2 b);

::max<double>(4, 7.2);  // OK: RT = double, T1 y T2 se deducen
```

> **Recomendación**: Usa la versión simple con un solo parámetro `T`. Es más clara y suficiente.

---

### 1.3.2 Deducir el tipo de retorno (C++14+)

Desde **C++14**, puedes dejar que el compilador **deduzca el tipo de retorno** usando `auto`:

```cpp
// basics/maxauto.hpp
template<typename T1, typename T2>
auto max(T1 a, T2 b)
{
    return b < a ? a : b;
}
```

- `auto` sin `->` → **deducción desde el cuerpo de la función**.
- Requiere que **todos los `return`** devuelvan tipos compatibles.
- El código debe estar disponible (no solo declaración).

---

#### Antes de C++14 (C++11): `decltype`

```cpp
// basics/maxdecltype.hpp
template<typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(b < a ? a : b)
{
    return b < a ? a : b;
}
```

- Usa `-> decltype(...)` para especificar el tipo de retorno.
- `decltype(b < a ? a : b)` sigue las reglas del operador ternario.

> **Truco**: Puedes usar `true ? a : b` en la declaración (no requiere evaluación):

```cpp
auto max(T1 a, T2 b) -> decltype(true ? a : b);
```

---

#### Problema: referencias no deseadas

`decltype` puede devolver **referencias**. Para evitarlo, usa `std::decay`:

```cpp
// basics/maxdecltypedecay.hpp
#include <type_traits>

template<typename T1, typename T2>
auto max(T1 a, T2 b) -> typename std::decay<decltype(true ? a : b)>::type
{
    return b < a ? a : b;
}
```

- `std::decay<T>` elimina `const`, `volatile` y referencias.
- `typename` es obligatorio para acceder a tipos dependientes.

> `auto` como tipo de retorno **siempre aplica decay** (como en `auto x = expr;`).

---

### 1.3.3 Tipo común con `std::common_type` (C++11+)

La biblioteca estándar ofrece `std::common_type` para obtener el **tipo común** de dos o más tipos:

```cpp
// basics/maxcommon.hpp
#include <type_traits>

template<typename T1, typename T2>
std::common_type_t<T1, T2> max(T1 a, T2 b)
{
    return b < a ? a : b;
}
```

- `std::common_type_t<T1, T2>` → alias para `typename std::common_type<T1,T2>::type` (C++14+).
- Usa las mismas reglas que `operator ?:`, con **conversión aritmética común**.
- **Decaimiento automático** (elimina referencias, `const`, etc.).

```cpp
::max(4, 7.2);   // → 7.2 (double)
::max(7.2, 4);   // → 7.2 (double)
```

---

## 1.4 Argumentos por defecto en plantillas

Puedes definir **valores por defecto** para **parámetros de plantilla**:

```cpp
template<typename T = std::string>
void f(T = "");
```

```cpp
f();  // OK → T = std::string
```

> **Importante**: La deducción **no funciona** con argumentos por defecto en llamadas si no se pasa ningún argumento.

---

## Resumen: Opciones para `max(T1, T2)`

| Versión | Ventajas | Desventajas | Recomendado |
|-------|--------|-----------|------------|
| `T max(T, T)` | Simple, deducción total | Solo tipos iguales | Sí |
| `auto max(T1, T2)` (C++14) | Deducción de retorno | Requiere cuerpo visible | Sí |
| `-> decltype(...)` | Compatible C++11 | Complejo, riesgo de referencias | Solo si necesitas C++11 |
| `common_type_t` | Tipo común seguro | Necesita `<type_traits>` | Buena opción |
| `RT max(T1, T2)` | Control total | Llamadas verbosas | Evitar |

---

> **Mejor práctica**: Usa `auto max(T1 a, T2 b)` en C++14+  
> Es claro, seguro y deducido automáticamente.

---

> **Siguiente**: [Capítulo 2 - Plantillas de clase →](#)
```

---

**Listo para GitHub**:  
- Usa encabezados claros  
- Código bien formateado  
- Tablas y ejemplos prácticos  
- En español técnico y accesible  

Puedes seguir extendiendo el README con los próximos capítulos sin romper el estilo.
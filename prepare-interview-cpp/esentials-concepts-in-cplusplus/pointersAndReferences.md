# TEMA: PUNTEROS Y REFERENCIAS EN C++

---

## **1. Concepto general**

En C++, **una variable normal guarda un valor**, pero un **puntero** guarda **una dirección de memoria**.
Una **referencia**, en cambio, **no guarda una dirección**, sino que **es otro nombre (alias)** de una variable existente.

---

## 🔸 **2. Diferencias entre `*` y `&`**

| Símbolo | Significado en declaración | Significado en uso                                |
| ------- | -------------------------- | ------------------------------------------------- |
| `*`     | Declara un **puntero**     | **Desreferencia** (accede al valor al que apunta) |
| `&`     | Declara una **referencia** | **Obtiene la dirección** de una variable          |

### Ejemplo:

```cpp
int x = 10;
int* ptr = &x;   // ptr guarda la dirección de x
int& ref = x;    // ref es otro nombre para x

*ptr = 20;       // cambia el valor de x a 20 (porque *ptr accede al valor)
ref = 30;        // también cambia el valor de x (ref es un alias)

std::cout << x;  // imprime 30
```

💡 **Idea:**

* El puntero puede apuntar a distintos objetos durante su vida.
* La referencia no puede “reapuntar” a otro objeto una vez inicializada.

---

## 🧱 **3. Puntero nulo (`nullptr`)**

Un puntero que **no apunta a ninguna dirección válida**.

```cpp
int* p = nullptr; // puntero nulo (moderno desde C++11)

if (p == nullptr)
    std::cout << "No apunta a nada\n";
```

Usar `nullptr` es preferible a `NULL` o `0` porque **tiene tipo seguro** (`std::nullptr_t`).

⚠️ **Error común:** desreferenciar un puntero nulo:

```cpp
*p = 5; // ❌ ERROR: comportamiento indefinido si p == nullptr
```

---

## 🔧 **4. Punteros a funciones**

Un **puntero a función** guarda la dirección de una función (como si fuera un callback).

``` cpp
int suma(int a, int b)
{
    return a + b;
}

// puntero a función que recibe (int, int) y devuelve int
int (*pf)(int, int) = &suma;

// se puede llamar así:
int resultado = pf(3, 4); // == 7
```
También puedes usar `typedef` o `using` para simplificar:

```cpp
using FuncPtr = int(*)(int, int);
FuncPtr f = suma;
```


## Cómo usar typedef y using en C++

Ambos (typedef y using) sirven para definir alias de tipos, es decir, darle un nuevo nombre a un tipo existente.

### 1. typedef — forma clásica (desde C y C++98)

typedef existe desde C y fue heredado por C++98.
Su sintaxis es algo más “inversa” a la lectura natural:

```cpp
   typedef unsigned long ulong;   // alias de tipo
    typedef int* IntPtr;           // alias para puntero a int
```
Ejemplo con contenedores STL:

```cpp
    typedef std::vector<int> IntVector;
    typedef std::map<std::string, int> PhoneBook;
```
➡️ Ventaja: funciona en todas las versiones de C y C++ (compatible con C++98, C++03, etc.).<br>
➡️ Desventaja: la sintaxis se vuelve confusa con tipos plantillas (templates).

### ⚙️ 2. using — forma moderna (desde C++11)

Introducido en C++11, using simplifica la sintaxis y la hace más intuitiva:

``` c++
using ulong = unsigned long;       // igual que typedef
using IntPtr = int*;
``` 

Ejemplo con plantillas:

``` c++
    template<typename T>
    using Vec = std::vector<T>;        // alias template
    Vec<int> vi;                      // equivale a std::vector<int>
```

➡️ Ventajas:
- Mucho más legible.
- Puede definir alias de plantillas (lo que typedef NO puede).
- Mejor compatibilidad con decltype, std::enable_if, y metaprogramación moderna.

---

## 🧠 **5. Punteros inteligentes**

Los **smart pointers** del `<memory>` son clases que administran automáticamente la memoria del objeto que apuntan, evitando fugas o dobles liberaciones.

### 🔹 `std::unique_ptr<T>`

* Posee **exclusivamente** el objeto.
* No se puede copiar, solo mover (`std::move`).

```cpp
std::unique_ptr<int> p1 = std::make_unique<int>(5);
std::unique_ptr<int> p2 = std::move(p1); // transfiere propiedad
```

### 🔹 `std::shared_ptr<T>`

* Permite **propiedad compartida** del objeto.
* Lleva un **contador de referencias** interno.

```cpp
std::shared_ptr<int> a = std::make_shared<int>(10);
std::shared_ptr<int> b = a; // ahora ambos comparten el mismo recurso
```

### 🔹 `std::weak_ptr<T>`

* Observa un `shared_ptr`, **sin aumentar** el contador de referencias.
* Útil para evitar ciclos.

```cpp
std::weak_ptr<int> w = a; // no evita que 'a' se libere
```

---

# 🧩 **Pequeño problema para practicar**

### 💬 Enunciado:

Implementa un pequeño programa que:

1. Cree un entero `x = 42`
2. Cree un puntero `p` que apunte a `x`
3. Cree una referencia `r` que referencie a `x`
4. Cambie el valor de `x` **a través del puntero** y **a través de la referencia**
5. Imprima los valores de `x`, `*p` y `r` para mostrar que son iguales

---

🧭 **Extra opcional:**
Crea también un `std::unique_ptr<int>` que apunte a un nuevo entero con valor 100 y muéstralo por pantalla.

---

¿Quieres intentar escribir el código tú y luego te corrijo explicando línea por línea?

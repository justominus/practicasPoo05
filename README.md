# 🦁 Sistema de Login para Zoológico

Sistema de autenticación para zoológico desarrollado en C++ con Windows Forms. Implementación de login con perfiles (Administrador, Cajero, Dueño) usando herencia, interfaces gráficas y validación de usuarios.

## 📋 Descripción

Este proyecto implementa un sistema de autenticación completo para un zoológico con las siguientes características:

- **Validación de credenciales** con mensajes de error apropiados
- **Mensajes MessageBox** con iconos según el tipo de mensaje (información, advertencia, error, pregunta)
- **Navegación entre formularios** (Login → Menú Principal)
- **Gestión de perfiles de usuario** con diferentes niveles de acceso

## 🏗️ Estructura del Proyecto

```
practicasPoo05/
├── src/
│   ├── Models/
│   │   ├── Usuario.h           # Clase base abstracta
│   │   ├── Administrador.h     # Perfil de administrador
│   │   ├── Cajero.h            # Perfil de cajero
│   │   ├── Dueno.h             # Perfil de dueño
│   │   └── ServicioAutenticacion.h  # Servicio de autenticación
│   ├── Forms/
│   │   ├── FormLogin.h         # Formulario de inicio de sesión
│   │   └── FormMenuPrincipal.h # Menú principal del sistema
│   └── main.cpp                # Punto de entrada de la aplicación
├── ZoologicoLogin.sln          # Solución de Visual Studio
├── ZoologicoLogin.vcxproj      # Proyecto de Visual Studio
├── .gitignore                  # Archivos ignorados por Git
└── README.md                   # Este archivo
```

## 🔐 Credenciales de Prueba

| Usuario   | Contraseña  | Perfil         |
|-----------|-------------|----------------|
| admin     | admin123    | Administrador  |
| cajero    | cajero123   | Cajero         |
| dueno     | dueno123    | Dueño          |
| admin2    | admin456    | Administrador  |
| cajero2   | cajero456   | Cajero         |

## 👥 Perfiles de Usuario

### 🔧 Administrador
- Gestión completa del sistema
- Administración de usuarios
- Configuración del zoológico
- Reportes y estadísticas
- Gestión de animales
- Control de inventario

### 💵 Cajero
- Venta de boletos
- Registro de visitantes
- Consulta de precios
- Cierre de caja
- Emisión de recibos

### 👔 Dueño
- Acceso total al sistema
- Visualización de reportes financieros
- Gestión de empleados
- Decisiones estratégicas
- Supervisión general
- Aprobación de presupuestos

## 🎯 Características Implementadas

### Validación de Credenciales
- ✅ Validación de campos vacíos
- ✅ Validación de longitud mínima de usuario (3 caracteres)
- ✅ Validación de longitud mínima de contraseña (5 caracteres)
- ✅ Límite de 3 intentos fallidos
- ✅ Bloqueo de aplicación tras exceder intentos

### MessageBox con Iconos Apropiados
- ℹ️ **Información**: Bienvenida, acciones exitosas
- ⚠️ **Advertencia**: Errores de validación, acceso denegado
- ❌ **Error**: Credenciales incorrectas, bloqueo de acceso
- ❓ **Pregunta**: Confirmaciones (salir, cerrar sesión)

### Navegación entre Formularios
- Login → Menú Principal (tras autenticación exitosa)
- Menú Principal → Login (al cerrar sesión)
- Cierre de aplicación con confirmación

### Interfaz de Usuario
- Diseño moderno con colores temáticos del zoológico
- Panel lateral con opciones de menú
- Barra superior con información del usuario
- Reloj en tiempo real
- Visualización de permisos según el perfil

## 🛠️ Requisitos

- **Sistema Operativo**: Windows 10 o superior
- **IDE**: Visual Studio 2019 o superior
- **Framework**: .NET Framework 4.7.2 o superior
- **Componentes**: Windows Forms con soporte CLR

## 🚀 Instrucciones de Compilación

1. Abrir `ZoologicoLogin.sln` en Visual Studio
2. Seleccionar configuración (Debug/Release) y plataforma (x86/x64)
3. Compilar la solución (Ctrl + Shift + B)
4. Ejecutar el proyecto (F5 o Ctrl + F5)

## 📐 Conceptos de POO Aplicados

### Herencia
```cpp
// Clase base abstracta
public ref class Usuario abstract { ... }

// Clases derivadas
public ref class Administrador : public Usuario { ... }
public ref class Cajero : public Usuario { ... }
public ref class Dueno : public Usuario { ... }
```

### Polimorfismo
```cpp
// Métodos virtuales abstractos en la clase base
virtual String^ ObtenerTipoPerfil() abstract;
virtual String^ ObtenerPermisos() abstract;

// Implementación en clases derivadas
virtual String^ ObtenerTipoPerfil() override { return "Administrador"; }
```

### Encapsulamiento
```cpp
// Propiedades con acceso controlado
property String^ NombreUsuario {
    String^ get() { return nombreUsuario; }
}
```

## 📝 Licencia

Este proyecto es parte de las prácticas de Programación Orientada a Objetos.

---
*Desarrollado como práctica académica de POO en C++ con Windows Forms*

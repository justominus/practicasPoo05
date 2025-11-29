#pragma once

#include "Usuario.h"
#include "Administrador.h"
#include "Cajero.h"
#include "Dueno.h"

using namespace System;
using namespace System::Collections::Generic;

namespace ZoologicoLogin {
    namespace Models {

        /// <summary>
        /// Servicio de autenticación para gestionar el login del sistema del zoológico
        /// </summary>
        public ref class ServicioAutenticacion {
        private:
            List<Usuario^>^ usuarios;
            Usuario^ usuarioActual;

            /// <summary>
            /// Inicializa los usuarios predeterminados del sistema
            /// </summary>
            void InicializarUsuarios() {
                usuarios = gcnew List<Usuario^>();
                
                // Usuarios predeterminados del sistema
                usuarios->Add(gcnew Administrador("admin", "admin123", "Juan Pérez García"));
                usuarios->Add(gcnew Cajero("cajero", "cajero123", "María López Sánchez"));
                usuarios->Add(gcnew Dueno("dueno", "dueno123", "Carlos Rodríguez Martínez"));
                
                // Usuarios adicionales para demostración
                usuarios->Add(gcnew Administrador("admin2", "admin456", "Ana Torres Ruiz"));
                usuarios->Add(gcnew Cajero("cajero2", "cajero456", "Pedro González Díaz"));
            }

        public:
            /// <summary>
            /// Constructor del servicio de autenticación
            /// </summary>
            ServicioAutenticacion() {
                usuarioActual = nullptr;
                InicializarUsuarios();
            }

            /// <summary>
            /// Intenta autenticar un usuario con las credenciales proporcionadas
            /// </summary>
            /// <param name="nombreUsuario">Nombre de usuario</param>
            /// <param name="contrasena">Contraseña del usuario</param>
            /// <returns>true si la autenticación fue exitosa, false en caso contrario</returns>
            bool Autenticar(String^ nombreUsuario, String^ contrasena) {
                // Validar que los campos no estén vacíos
                if (String::IsNullOrWhiteSpace(nombreUsuario) || 
                    String::IsNullOrWhiteSpace(contrasena)) {
                    return false;
                }

                // Buscar usuario con las credenciales proporcionadas
                for each (Usuario^ usuario in usuarios) {
                    if (usuario->ValidarCredenciales(nombreUsuario, contrasena)) {
                        usuarioActual = usuario;
                        return true;
                    }
                }
                
                return false;
            }

            /// <summary>
            /// Cierra la sesión del usuario actual
            /// </summary>
            void CerrarSesion() {
                usuarioActual = nullptr;
            }

            /// <summary>
            /// Verifica si hay una sesión activa
            /// </summary>
            /// <returns>true si hay un usuario autenticado, false en caso contrario</returns>
            bool SesionActiva() {
                return usuarioActual != nullptr;
            }

            /// <summary>
            /// Obtiene el usuario actualmente autenticado
            /// </summary>
            property Usuario^ UsuarioActual {
                Usuario^ get() { return usuarioActual; }
            }

            /// <summary>
            /// Valida que el nombre de usuario tenga el formato correcto
            /// </summary>
            /// <param name="nombreUsuario">Nombre de usuario a validar</param>
            /// <returns>Mensaje de error o cadena vacía si es válido</returns>
            static String^ ValidarFormatoUsuario(String^ nombreUsuario) {
                if (String::IsNullOrWhiteSpace(nombreUsuario)) {
                    return "El nombre de usuario es requerido.";
                }
                if (nombreUsuario->Length < 3) {
                    return "El nombre de usuario debe tener al menos 3 caracteres.";
                }
                if (nombreUsuario->Length > 20) {
                    return "El nombre de usuario no puede exceder 20 caracteres.";
                }
                return String::Empty;
            }

            /// <summary>
            /// Valida que la contraseña tenga el formato correcto
            /// </summary>
            /// <param name="contrasena">Contraseña a validar</param>
            /// <returns>Mensaje de error o cadena vacía si es válida</returns>
            static String^ ValidarFormatoContrasena(String^ contrasena) {
                if (String::IsNullOrWhiteSpace(contrasena)) {
                    return L"La contraseña es requerida.";
                }
                if (contrasena->Length < 5) {
                    return L"La contraseña debe tener al menos 5 caracteres.";
                }
                return String::Empty;
            }
        };
    }
}

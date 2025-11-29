#pragma once

#include <string>

using namespace System;

namespace ZoologicoLogin {
    namespace Models {

        /// <summary>
        /// Clase base abstracta para representar un usuario del sistema de zoológico
        /// </summary>
        public ref class Usuario abstract {
        protected:
            String^ nombreUsuario;
            String^ contrasena;
            String^ nombreCompleto;

        public:
            /// <summary>
            /// Constructor de la clase Usuario
            /// </summary>
            /// <param name="usuario">Nombre de usuario para login</param>
            /// <param name="password">Contraseña del usuario</param>
            /// <param name="nombre">Nombre completo del usuario</param>
            Usuario(String^ usuario, String^ password, String^ nombre) {
                this->nombreUsuario = usuario;
                this->contrasena = password;
                this->nombreCompleto = nombre;
            }

            /// <summary>
            /// Valida las credenciales del usuario
            /// </summary>
            /// <param name="usuario">Nombre de usuario a validar</param>
            /// <param name="password">Contraseña a validar</param>
            /// <returns>true si las credenciales son correctas, false en caso contrario</returns>
            virtual bool ValidarCredenciales(String^ usuario, String^ password) {
                return this->nombreUsuario->Equals(usuario) && 
                       this->contrasena->Equals(password);
            }

            /// <summary>
            /// Obtiene el tipo de perfil del usuario (método abstracto)
            /// </summary>
            /// <returns>Cadena con el tipo de perfil</returns>
            virtual String^ ObtenerTipoPerfil() abstract;

            /// <summary>
            /// Obtiene los permisos del usuario (método abstracto)
            /// </summary>
            /// <returns>Cadena con la descripción de permisos</returns>
            virtual String^ ObtenerPermisos() abstract;

            // Propiedades
            property String^ NombreUsuario {
                String^ get() { return nombreUsuario; }
            }

            property String^ NombreCompleto {
                String^ get() { return nombreCompleto; }
            }
        };
    }
}

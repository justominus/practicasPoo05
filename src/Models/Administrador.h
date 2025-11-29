#pragma once

#include "Usuario.h"

namespace ZoologicoLogin {
    namespace Models {

        /// <summary>
        /// Clase que representa un usuario Administrador del zoológico
        /// Hereda de la clase base Usuario
        /// </summary>
        public ref class Administrador : public Usuario {
        public:
            /// <summary>
            /// Constructor de la clase Administrador
            /// </summary>
            /// <param name="usuario">Nombre de usuario para login</param>
            /// <param name="password">Contraseña del usuario</param>
            /// <param name="nombre">Nombre completo del administrador</param>
            Administrador(String^ usuario, String^ password, String^ nombre)
                : Usuario(usuario, password, nombre) {
            }

            /// <summary>
            /// Obtiene el tipo de perfil del administrador
            /// </summary>
            /// <returns>Cadena "Administrador"</returns>
            virtual String^ ObtenerTipoPerfil() override {
                return L"Administrador";
            }

            /// <summary>
            /// Obtiene los permisos del administrador
            /// </summary>
            /// <returns>Cadena con la descripción de permisos del administrador</returns>
            virtual String^ ObtenerPermisos() override {
                return L"- Gestión completa del sistema\n"
                        "- Administración de usuarios\n"
                        "- Configuración del zoológico\n"
                        "- Reportes y estadísticas\n"
                        "- Gestión de animales\n"
                        "- Control de inventario";
            }

            /// <summary>
            /// Función específica del administrador para gestionar usuarios
            /// </summary>
            void GestionarUsuarios() {
                // Lógica para gestionar usuarios
            }

            /// <summary>
            /// Función específica del administrador para generar reportes
            /// </summary>
            void GenerarReportes() {
                // Lógica para generar reportes
            }
        };
    }
}

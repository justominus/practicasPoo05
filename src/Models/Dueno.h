#pragma once

#include "Usuario.h"

namespace ZoologicoLogin {
    namespace Models {

        /// <summary>
        /// Clase que representa al Dueño del zoológico
        /// Hereda de la clase base Usuario
        /// </summary>
        public ref class Dueno : public Usuario {
        public:
            /// <summary>
            /// Constructor de la clase Dueno
            /// </summary>
            /// <param name="usuario">Nombre de usuario para login</param>
            /// <param name="password">Contraseña del usuario</param>
            /// <param name="nombre">Nombre completo del dueño</param>
            Dueno(String^ usuario, String^ password, String^ nombre)
                : Usuario(usuario, password, nombre) {
            }

            /// <summary>
            /// Obtiene el tipo de perfil del dueño
            /// </summary>
            /// <returns>Cadena "Dueño"</returns>
            virtual String^ ObtenerTipoPerfil() override {
                return L"Dueño";
            }

            /// <summary>
            /// Obtiene los permisos del dueño
            /// </summary>
            /// <returns>Cadena con la descripción de permisos del dueño</returns>
            virtual String^ ObtenerPermisos() override {
                return L"- Acceso total al sistema\n"
                        "- Visualización de reportes financieros\n"
                        "- Gestión de empleados\n"
                        "- Decisiones estratégicas\n"
                        "- Supervisión general\n"
                        "- Aprobación de presupuestos";
            }

            /// <summary>
            /// Función específica del dueño para ver reportes financieros
            /// </summary>
            void VerReportesFinancieros() {
                // Lógica para ver reportes financieros
            }

            /// <summary>
            /// Función específica del dueño para gestionar empleados
            /// </summary>
            void GestionarEmpleados() {
                // Lógica para gestionar empleados
            }
        };
    }
}

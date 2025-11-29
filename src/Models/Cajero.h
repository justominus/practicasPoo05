#pragma once

#include "Usuario.h"

namespace ZoologicoLogin {
    namespace Models {

        /// <summary>
        /// Clase que representa un usuario Cajero del zoológico
        /// Hereda de la clase base Usuario
        /// </summary>
        public ref class Cajero : public Usuario {
        public:
            /// <summary>
            /// Constructor de la clase Cajero
            /// </summary>
            /// <param name="usuario">Nombre de usuario para login</param>
            /// <param name="password">Contraseña del usuario</param>
            /// <param name="nombre">Nombre completo del cajero</param>
            Cajero(String^ usuario, String^ password, String^ nombre)
                : Usuario(usuario, password, nombre) {
            }

            /// <summary>
            /// Obtiene el tipo de perfil del cajero
            /// </summary>
            /// <returns>Cadena "Cajero"</returns>
            virtual String^ ObtenerTipoPerfil() override {
                return L"Cajero";
            }

            /// <summary>
            /// Obtiene los permisos del cajero
            /// </summary>
            /// <returns>Cadena con la descripción de permisos del cajero</returns>
            virtual String^ ObtenerPermisos() override {
                return L"- Venta de boletos\n"
                        "- Registro de visitantes\n"
                        "- Consulta de precios\n"
                        "- Cierre de caja\n"
                        "- Emisión de recibos";
            }

            /// <summary>
            /// Función específica del cajero para vender boletos
            /// </summary>
            void VenderBoleto() {
                // Lógica para vender boletos
            }

            /// <summary>
            /// Función específica del cajero para cerrar caja
            /// </summary>
            void CerrarCaja() {
                // Lógica para cerrar caja
            }
        };
    }
}

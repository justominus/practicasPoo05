#pragma once

#include "../Models/ServicioAutenticacion.h"
#include "../Models/Usuario.h"

namespace ZoologicoLogin {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace ZoologicoLogin::Models;

    /// <summary>
    /// Formulario del menú principal del sistema del zoológico
    /// Muestra opciones según el perfil del usuario autenticado
    /// </summary>
    public ref class FormMenuPrincipal : public System::Windows::Forms::Form {
    private:
        ServicioAutenticacion^ servicioAuth;

        // Componentes de la interfaz
        System::Windows::Forms::Panel^ panelSuperior;
        System::Windows::Forms::Panel^ panelLateral;
        System::Windows::Forms::Panel^ panelContenido;
        System::Windows::Forms::Label^ lblBienvenida;
        System::Windows::Forms::Label^ lblPerfil;
        System::Windows::Forms::Label^ lblFechaHora;
        System::Windows::Forms::Button^ btnCerrarSesion;
        System::Windows::Forms::Button^ btnPerfil;
        System::Windows::Forms::Button^ btnAnimales;
        System::Windows::Forms::Button^ btnVisitantes;
        System::Windows::Forms::Button^ btnVentas;
        System::Windows::Forms::Button^ btnReportes;
        System::Windows::Forms::Button^ btnConfiguracion;
        System::Windows::Forms::Button^ btnUsuarios;
        System::Windows::Forms::RichTextBox^ rtbInformacion;
        System::Windows::Forms::Timer^ timerReloj;

    public:
        /// <summary>
        /// Constructor del formulario de menú principal
        /// </summary>
        /// <param name="servicio">Servicio de autenticación con el usuario logueado</param>
        FormMenuPrincipal(ServicioAutenticacion^ servicio) {
            servicioAuth = servicio;
            InitializeComponent();
            ConfigurarInterfazSegunPerfil();
            MostrarInformacionBienvenida();
        }

    protected:
        /// <summary>
        /// Destructor del formulario
        /// </summary>
        ~FormMenuPrincipal() {
            if (components) {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

        /// <summary>
        /// Inicializa los componentes del formulario
        /// </summary>
        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            
            this->panelSuperior = (gcnew System::Windows::Forms::Panel());
            this->panelLateral = (gcnew System::Windows::Forms::Panel());
            this->panelContenido = (gcnew System::Windows::Forms::Panel());
            this->lblBienvenida = (gcnew System::Windows::Forms::Label());
            this->lblPerfil = (gcnew System::Windows::Forms::Label());
            this->lblFechaHora = (gcnew System::Windows::Forms::Label());
            this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
            this->btnPerfil = (gcnew System::Windows::Forms::Button());
            this->btnAnimales = (gcnew System::Windows::Forms::Button());
            this->btnVisitantes = (gcnew System::Windows::Forms::Button());
            this->btnVentas = (gcnew System::Windows::Forms::Button());
            this->btnReportes = (gcnew System::Windows::Forms::Button());
            this->btnConfiguracion = (gcnew System::Windows::Forms::Button());
            this->btnUsuarios = (gcnew System::Windows::Forms::Button());
            this->rtbInformacion = (gcnew System::Windows::Forms::RichTextBox());
            this->timerReloj = (gcnew System::Windows::Forms::Timer(this->components));

            this->SuspendLayout();

            // 
            // panelSuperior
            // 
            this->panelSuperior->BackColor = System::Drawing::Color::ForestGreen;
            this->panelSuperior->Dock = System::Windows::Forms::DockStyle::Top;
            this->panelSuperior->Location = System::Drawing::Point(0, 0);
            this->panelSuperior->Name = L"panelSuperior";
            this->panelSuperior->Size = System::Drawing::Size(900, 80);

            // 
            // lblBienvenida
            // 
            this->lblBienvenida->AutoSize = true;
            this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->lblBienvenida->ForeColor = System::Drawing::Color::White;
            this->lblBienvenida->Location = System::Drawing::Point(20, 15);
            this->lblBienvenida->Name = L"lblBienvenida";
            this->lblBienvenida->Text = L"Bienvenido al Zoológico Salvaje";

            // 
            // lblPerfil
            // 
            this->lblPerfil->AutoSize = true;
            this->lblPerfil->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblPerfil->ForeColor = System::Drawing::Color::LightGreen;
            this->lblPerfil->Location = System::Drawing::Point(22, 50);
            this->lblPerfil->Name = L"lblPerfil";
            this->lblPerfil->Text = L"Perfil: ";

            // 
            // lblFechaHora
            // 
            this->lblFechaHora->AutoSize = true;
            this->lblFechaHora->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblFechaHora->ForeColor = System::Drawing::Color::White;
            this->lblFechaHora->Location = System::Drawing::Point(700, 30);
            this->lblFechaHora->Name = L"lblFechaHora";
            this->lblFechaHora->Text = DateTime::Now.ToString("dd/MM/yyyy HH:mm:ss");

            // 
            // btnCerrarSesion
            // 
            this->btnCerrarSesion->BackColor = System::Drawing::Color::Tomato;
            this->btnCerrarSesion->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnCerrarSesion->ForeColor = System::Drawing::Color::White;
            this->btnCerrarSesion->Location = System::Drawing::Point(770, 45);
            this->btnCerrarSesion->Name = L"btnCerrarSesion";
            this->btnCerrarSesion->Size = System::Drawing::Size(110, 30);
            this->btnCerrarSesion->Text = L"Cerrar Sesión";
            this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &FormMenuPrincipal::btnCerrarSesion_Click);

            this->panelSuperior->Controls->Add(this->lblBienvenida);
            this->panelSuperior->Controls->Add(this->lblPerfil);
            this->panelSuperior->Controls->Add(this->lblFechaHora);
            this->panelSuperior->Controls->Add(this->btnCerrarSesion);

            // 
            // panelLateral
            // 
            this->panelLateral->BackColor = System::Drawing::Color::DarkGreen;
            this->panelLateral->Location = System::Drawing::Point(0, 80);
            this->panelLateral->Name = L"panelLateral";
            this->panelLateral->Size = System::Drawing::Size(200, 470);

            // Botones del menú lateral
            int yPos = 20;
            int btnHeight = 45;
            int btnSpacing = 55;

            // 
            // btnPerfil
            // 
            this->btnPerfil = CrearBotonMenu(L"👤 Mi Perfil", yPos);
            this->btnPerfil->Click += gcnew System::EventHandler(this, &FormMenuPrincipal::btnPerfil_Click);
            yPos += btnSpacing;

            // 
            // btnAnimales
            // 
            this->btnAnimales = CrearBotonMenu(L"🦁 Animales", yPos);
            this->btnAnimales->Click += gcnew System::EventHandler(this, &FormMenuPrincipal::btnAnimales_Click);
            yPos += btnSpacing;

            // 
            // btnVisitantes
            // 
            this->btnVisitantes = CrearBotonMenu(L"👥 Visitantes", yPos);
            this->btnVisitantes->Click += gcnew System::EventHandler(this, &FormMenuPrincipal::btnVisitantes_Click);
            yPos += btnSpacing;

            // 
            // btnVentas
            // 
            this->btnVentas = CrearBotonMenu(L"🎫 Ventas", yPos);
            this->btnVentas->Click += gcnew System::EventHandler(this, &FormMenuPrincipal::btnVentas_Click);
            yPos += btnSpacing;

            // 
            // btnReportes
            // 
            this->btnReportes = CrearBotonMenu(L"📊 Reportes", yPos);
            this->btnReportes->Click += gcnew System::EventHandler(this, &FormMenuPrincipal::btnReportes_Click);
            yPos += btnSpacing;

            // 
            // btnUsuarios
            // 
            this->btnUsuarios = CrearBotonMenu(L"👥 Usuarios", yPos);
            this->btnUsuarios->Click += gcnew System::EventHandler(this, &FormMenuPrincipal::btnUsuarios_Click);
            yPos += btnSpacing;

            // 
            // btnConfiguracion
            // 
            this->btnConfiguracion = CrearBotonMenu(L"⚙️ Configuración", yPos);
            this->btnConfiguracion->Click += gcnew System::EventHandler(this, &FormMenuPrincipal::btnConfiguracion_Click);

            this->panelLateral->Controls->Add(this->btnPerfil);
            this->panelLateral->Controls->Add(this->btnAnimales);
            this->panelLateral->Controls->Add(this->btnVisitantes);
            this->panelLateral->Controls->Add(this->btnVentas);
            this->panelLateral->Controls->Add(this->btnReportes);
            this->panelLateral->Controls->Add(this->btnUsuarios);
            this->panelLateral->Controls->Add(this->btnConfiguracion);

            // 
            // panelContenido
            // 
            this->panelContenido->BackColor = System::Drawing::Color::White;
            this->panelContenido->Location = System::Drawing::Point(200, 80);
            this->panelContenido->Name = L"panelContenido";
            this->panelContenido->Size = System::Drawing::Size(700, 470);

            // 
            // rtbInformacion
            // 
            this->rtbInformacion->BackColor = System::Drawing::Color::White;
            this->rtbInformacion->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->rtbInformacion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->rtbInformacion->Location = System::Drawing::Point(30, 30);
            this->rtbInformacion->Name = L"rtbInformacion";
            this->rtbInformacion->ReadOnly = true;
            this->rtbInformacion->Size = System::Drawing::Size(640, 410);

            this->panelContenido->Controls->Add(this->rtbInformacion);

            // 
            // timerReloj
            // 
            this->timerReloj->Interval = 1000;
            this->timerReloj->Tick += gcnew System::EventHandler(this, &FormMenuPrincipal::timerReloj_Tick);
            this->timerReloj->Start();

            // 
            // FormMenuPrincipal
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::DarkSeaGreen;
            this->ClientSize = System::Drawing::Size(900, 550);
            this->Controls->Add(this->panelSuperior);
            this->Controls->Add(this->panelLateral);
            this->Controls->Add(this->panelContenido);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"FormMenuPrincipal";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Zoológico Salvaje - Menú Principal";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormMenuPrincipal::FormMenuPrincipal_FormClosing);

            this->ResumeLayout(false);
        }

        /// <summary>
        /// Crea un botón con el estilo del menú lateral
        /// </summary>
        System::Windows::Forms::Button^ CrearBotonMenu(String^ texto, int yPosition) {
            System::Windows::Forms::Button^ btn = gcnew System::Windows::Forms::Button();
            btn->BackColor = System::Drawing::Color::DarkGreen;
            btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btn->FlatAppearance->BorderSize = 0;
            btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            btn->ForeColor = System::Drawing::Color::White;
            btn->Location = System::Drawing::Point(10, yPosition);
            btn->Size = System::Drawing::Size(180, 45);
            btn->Text = texto;
            btn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            btn->Cursor = System::Windows::Forms::Cursors::Hand;
            return btn;
        }

        /// <summary>
        /// Configura la interfaz según el perfil del usuario
        /// </summary>
        void ConfigurarInterfazSegunPerfil() {
            if (servicioAuth->UsuarioActual == nullptr) return;

            String^ tipoPerfil = servicioAuth->UsuarioActual->ObtenerTipoPerfil();
            
            lblPerfil->Text = L"Perfil: " + tipoPerfil + L" | Usuario: " + 
                              servicioAuth->UsuarioActual->NombreCompleto;

            // Configurar visibilidad de botones según el perfil
            if (tipoPerfil == "Cajero") {
                // El cajero solo puede acceder a ventas y visitantes
                btnAnimales->Visible = false;
                btnReportes->Visible = false;
                btnUsuarios->Visible = false;
                btnConfiguracion->Visible = false;
            }
            else if (tipoPerfil == "Administrador") {
                // El administrador tiene acceso a todo excepto configuración financiera
                btnConfiguracion->Visible = true;
            }
            else if (tipoPerfil == L"Dueño") {
                // El dueño tiene acceso completo
                btnConfiguracion->Visible = true;
                btnUsuarios->Visible = true;
            }
        }

        /// <summary>
        /// Muestra el mensaje de bienvenida con información del usuario
        /// </summary>
        void MostrarInformacionBienvenida() {
            if (servicioAuth->UsuarioActual == nullptr) return;

            String^ info = L"══════════════════════════════════════════════\n";
            info += L"         🦁 BIENVENIDO AL ZOOLÓGICO SALVAJE 🦁\n";
            info += L"══════════════════════════════════════════════\n\n";
            info += L"Usuario: " + servicioAuth->UsuarioActual->NombreCompleto + L"\n";
            info += L"Perfil: " + servicioAuth->UsuarioActual->ObtenerTipoPerfil() + L"\n\n";
            info += L"══════════════════════════════════════════════\n";
            info += L"                    PERMISOS\n";
            info += L"══════════════════════════════════════════════\n\n";
            info += servicioAuth->UsuarioActual->ObtenerPermisos() + L"\n\n";
            info += L"══════════════════════════════════════════════\n";
            info += L"Seleccione una opción del menú lateral para comenzar.\n";

            rtbInformacion->Text = info;
        }

        /// <summary>
        /// Actualiza el reloj en tiempo real
        /// </summary>
        void timerReloj_Tick(System::Object^ sender, System::EventArgs^ e) {
            lblFechaHora->Text = DateTime::Now.ToString("dd/MM/yyyy HH:mm:ss");
        }

        /// <summary>
        /// Maneja el click en el botón de perfil
        /// </summary>
        void btnPerfil_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ info = L"══════════════════════════════════════════════\n";
            info += L"              📋 MI PERFIL\n";
            info += L"══════════════════════════════════════════════\n\n";
            info += L"Nombre: " + servicioAuth->UsuarioActual->NombreCompleto + L"\n";
            info += L"Usuario: " + servicioAuth->UsuarioActual->NombreUsuario + L"\n";
            info += L"Tipo de Perfil: " + servicioAuth->UsuarioActual->ObtenerTipoPerfil() + L"\n\n";
            info += L"══════════════════════════════════════════════\n";
            info += L"                 PERMISOS ASIGNADOS\n";
            info += L"══════════════════════════════════════════════\n\n";
            info += servicioAuth->UsuarioActual->ObtenerPermisos();

            rtbInformacion->Text = info;

            MessageBox::Show(
                L"Información del perfil cargada correctamente.",
                L"Mi Perfil",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information
            );
        }

        /// <summary>
        /// Maneja el click en el botón de animales
        /// </summary>
        void btnAnimales_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ info = L"══════════════════════════════════════════════\n";
            info += L"              🦁 GESTIÓN DE ANIMALES\n";
            info += L"══════════════════════════════════════════════\n\n";
            info += L"Esta sección permite gestionar:\n\n";
            info += L"• Registro de nuevos animales\n";
            info += L"• Actualización de información\n";
            info += L"• Control de hábitats\n";
            info += L"• Historial médico\n";
            info += L"• Alimentación y cuidados\n\n";
            info += L"══════════════════════════════════════════════\n";
            info += L"Funcionalidad en desarrollo...\n";

            rtbInformacion->Text = info;

            MessageBox::Show(
                L"Módulo de Animales en desarrollo.\n\nPróximamente disponible.",
                L"Gestión de Animales",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information
            );
        }

        /// <summary>
        /// Maneja el click en el botón de visitantes
        /// </summary>
        void btnVisitantes_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ info = L"══════════════════════════════════════════════\n";
            info += L"              👥 GESTIÓN DE VISITANTES\n";
            info += L"══════════════════════════════════════════════\n\n";
            info += L"Esta sección permite gestionar:\n\n";
            info += L"• Registro de visitantes\n";
            info += L"• Control de entradas y salidas\n";
            info += L"• Estadísticas de visitas\n";
            info += L"• Membresías y pases\n\n";
            info += L"══════════════════════════════════════════════\n";
            info += L"Funcionalidad en desarrollo...\n";

            rtbInformacion->Text = info;

            MessageBox::Show(
                L"Módulo de Visitantes en desarrollo.\n\nPróximamente disponible.",
                L"Gestión de Visitantes",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information
            );
        }

        /// <summary>
        /// Maneja el click en el botón de ventas
        /// </summary>
        void btnVentas_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ info = L"══════════════════════════════════════════════\n";
            info += L"              🎫 MÓDULO DE VENTAS\n";
            info += L"══════════════════════════════════════════════\n\n";
            info += L"Esta sección permite:\n\n";
            info += L"• Venta de boletos\n";
            info += L"• Tipos de entrada:\n";
            info += L"  - Adulto: $50.00\n";
            info += L"  - Niño: $25.00\n";
            info += L"  - Tercera edad: $30.00\n";
            info += L"  - Estudiante: $35.00\n\n";
            info += L"• Cierre de caja\n";
            info += L"• Historial de ventas\n\n";
            info += L"══════════════════════════════════════════════\n";

            rtbInformacion->Text = info;

            MessageBox::Show(
                L"Módulo de Ventas en desarrollo.\n\nPróximamente disponible.",
                L"Ventas",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information
            );
        }

        /// <summary>
        /// Maneja el click en el botón de reportes
        /// </summary>
        void btnReportes_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ tipoPerfil = servicioAuth->UsuarioActual->ObtenerTipoPerfil();
            
            if (tipoPerfil == "Cajero") {
                MessageBox::Show(
                    L"No tiene permisos para acceder a esta sección.\n\n" +
                    L"Contacte al administrador si necesita acceso.",
                    L"Acceso Denegado",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Warning
                );
                return;
            }

            String^ info = L"══════════════════════════════════════════════\n";
            info += L"              📊 REPORTES Y ESTADÍSTICAS\n";
            info += L"══════════════════════════════════════════════\n\n";
            info += L"Reportes disponibles:\n\n";
            info += L"• Reporte de ventas diarias\n";
            info += L"• Estadísticas de visitantes\n";
            info += L"• Inventario de animales\n";
            info += L"• Reporte financiero mensual\n";
            info += L"• Análisis de tendencias\n\n";
            info += L"══════════════════════════════════════════════\n";

            rtbInformacion->Text = info;

            MessageBox::Show(
                L"Módulo de Reportes en desarrollo.\n\nPróximamente disponible.",
                L"Reportes",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information
            );
        }

        /// <summary>
        /// Maneja el click en el botón de usuarios
        /// </summary>
        void btnUsuarios_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ tipoPerfil = servicioAuth->UsuarioActual->ObtenerTipoPerfil();
            
            if (tipoPerfil == "Cajero") {
                MessageBox::Show(
                    L"No tiene permisos para acceder a esta sección.\n\n" +
                    L"Contacte al administrador si necesita acceso.",
                    L"Acceso Denegado",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Warning
                );
                return;
            }

            String^ info = L"══════════════════════════════════════════════\n";
            info += L"              👥 GESTIÓN DE USUARIOS\n";
            info += L"══════════════════════════════════════════════\n\n";
            info += L"Esta sección permite:\n\n";
            info += L"• Crear nuevos usuarios\n";
            info += L"• Modificar usuarios existentes\n";
            info += L"• Asignar perfiles y permisos\n";
            info += L"• Desactivar cuentas\n";
            info += L"• Restablecer contraseñas\n\n";
            info += L"══════════════════════════════════════════════\n";

            rtbInformacion->Text = info;

            MessageBox::Show(
                L"Módulo de Usuarios en desarrollo.\n\nPróximamente disponible.",
                L"Gestión de Usuarios",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information
            );
        }

        /// <summary>
        /// Maneja el click en el botón de configuración
        /// </summary>
        void btnConfiguracion_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ tipoPerfil = servicioAuth->UsuarioActual->ObtenerTipoPerfil();
            
            if (tipoPerfil == "Cajero") {
                MessageBox::Show(
                    L"No tiene permisos para acceder a esta sección.\n\n" +
                    L"Contacte al administrador si necesita acceso.",
                    L"Acceso Denegado",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Warning
                );
                return;
            }

            String^ info = L"══════════════════════════════════════════════\n";
            info += L"              ⚙️ CONFIGURACIÓN DEL SISTEMA\n";
            info += L"══════════════════════════════════════════════\n\n";
            info += L"Opciones disponibles:\n\n";
            info += L"• Configuración general\n";
            info += L"• Precios de boletos\n";
            info += L"• Horarios de operación\n";
            info += L"• Parámetros del sistema\n";
            info += L"• Copias de seguridad\n\n";
            info += L"══════════════════════════════════════════════\n";

            rtbInformacion->Text = info;

            MessageBox::Show(
                L"Módulo de Configuración en desarrollo.\n\nPróximamente disponible.",
                L"Configuración",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information
            );
        }

        /// <summary>
        /// Maneja el click en el botón de cerrar sesión
        /// </summary>
        void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
            System::Windows::Forms::DialogResult resultado = MessageBox::Show(
                L"¿Está seguro que desea cerrar sesión?\n\n" +
                L"Tendrá que volver a iniciar sesión para acceder al sistema.",
                L"Confirmar Cierre de Sesión",
                MessageBoxButtons::YesNo,
                MessageBoxIcon::Question
            );

            if (resultado == System::Windows::Forms::DialogResult::Yes) {
                MessageBox::Show(
                    L"Sesión cerrada correctamente.\n\n" +
                    L"¡Gracias por usar el Sistema del Zoológico Salvaje!",
                    L"Sesión Cerrada",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information
                );

                servicioAuth->CerrarSesion();
                this->DialogResult = System::Windows::Forms::DialogResult::OK;
                this->Close();
            }
        }

        /// <summary>
        /// Maneja el evento de cierre del formulario
        /// </summary>
        void FormMenuPrincipal_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
            if (servicioAuth->SesionActiva()) {
                System::Windows::Forms::DialogResult resultado = MessageBox::Show(
                    L"¿Está seguro que desea salir del sistema?\n\n" +
                    L"Se cerrará su sesión actual.",
                    L"Confirmar Salida",
                    MessageBoxButtons::YesNo,
                    MessageBoxIcon::Question
                );

                if (resultado == System::Windows::Forms::DialogResult::No) {
                    e->Cancel = true;
                }
                else {
                    servicioAuth->CerrarSesion();
                    timerReloj->Stop();
                }
            }
        }
    };
}

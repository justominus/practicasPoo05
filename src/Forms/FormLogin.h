#pragma once

#include "../Models/ServicioAutenticacion.h"

namespace ZoologicoLogin {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace ZoologicoLogin::Models;

    /// <summary>
    /// Formulario de inicio de sesión para el sistema del zoológico
    /// </summary>
    public ref class FormLogin : public System::Windows::Forms::Form {
    private:
        ServicioAutenticacion^ servicioAuth;
        int intentosFallidos;
        static const int MAX_INTENTOS = 3;

        // Componentes de la interfaz
        System::Windows::Forms::Panel^ panelPrincipal;
        System::Windows::Forms::Label^ lblTitulo;
        System::Windows::Forms::Label^ lblSubtitulo;
        System::Windows::Forms::Label^ lblUsuario;
        System::Windows::Forms::Label^ lblContrasena;
        System::Windows::Forms::TextBox^ txtUsuario;
        System::Windows::Forms::TextBox^ txtContrasena;
        System::Windows::Forms::Button^ btnIngresar;
        System::Windows::Forms::Button^ btnSalir;
        System::Windows::Forms::CheckBox^ chkMostrarContrasena;
        System::Windows::Forms::PictureBox^ picLogo;
        System::Windows::Forms::Label^ lblIntentos;

    public:
        /// <summary>
        /// Constructor del formulario de login
        /// </summary>
        FormLogin(void) {
            servicioAuth = gcnew ServicioAutenticacion();
            intentosFallidos = 0;
            InitializeComponent();
            ConfigurarEstilos();
        }

        /// <summary>
        /// Obtiene el servicio de autenticación
        /// </summary>
        property ServicioAutenticacion^ Servicio {
            ServicioAutenticacion^ get() { return servicioAuth; }
        }

    protected:
        /// <summary>
        /// Destructor del formulario
        /// </summary>
        ~FormLogin() {
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
            this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
            this->lblTitulo = (gcnew System::Windows::Forms::Label());
            this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
            this->lblUsuario = (gcnew System::Windows::Forms::Label());
            this->lblContrasena = (gcnew System::Windows::Forms::Label());
            this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
            this->txtContrasena = (gcnew System::Windows::Forms::TextBox());
            this->btnIngresar = (gcnew System::Windows::Forms::Button());
            this->btnSalir = (gcnew System::Windows::Forms::Button());
            this->chkMostrarContrasena = (gcnew System::Windows::Forms::CheckBox());
            this->picLogo = (gcnew System::Windows::Forms::PictureBox());
            this->lblIntentos = (gcnew System::Windows::Forms::Label());

            this->panelPrincipal->SuspendLayout();
            this->SuspendLayout();

            // 
            // panelPrincipal
            // 
            this->panelPrincipal->BackColor = System::Drawing::Color::White;
            this->panelPrincipal->Location = System::Drawing::Point(50, 30);
            this->panelPrincipal->Name = L"panelPrincipal";
            this->panelPrincipal->Size = System::Drawing::Size(400, 420);

            // 
            // picLogo (Símbolo del zoológico)
            // 
            this->picLogo->BackColor = System::Drawing::Color::ForestGreen;
            this->picLogo->Location = System::Drawing::Point(150, 20);
            this->picLogo->Name = L"picLogo";
            this->picLogo->Size = System::Drawing::Size(100, 100);
            this->picLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;

            // 
            // lblTitulo
            // 
            this->lblTitulo->AutoSize = false;
            this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
            this->lblTitulo->ForeColor = System::Drawing::Color::ForestGreen;
            this->lblTitulo->Location = System::Drawing::Point(20, 130);
            this->lblTitulo->Name = L"lblTitulo";
            this->lblTitulo->Size = System::Drawing::Size(360, 35);
            this->lblTitulo->Text = L"ZOOLÓGICO SALVAJE";
            this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

            // 
            // lblSubtitulo
            // 
            this->lblSubtitulo->AutoSize = false;
            this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblSubtitulo->ForeColor = System::Drawing::Color::Gray;
            this->lblSubtitulo->Location = System::Drawing::Point(20, 165);
            this->lblSubtitulo->Name = L"lblSubtitulo";
            this->lblSubtitulo->Size = System::Drawing::Size(360, 25);
            this->lblSubtitulo->Text = L"Sistema de Gestión - Iniciar Sesión";
            this->lblSubtitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

            // 
            // lblUsuario
            // 
            this->lblUsuario->AutoSize = true;
            this->lblUsuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblUsuario->ForeColor = System::Drawing::Color::DarkGreen;
            this->lblUsuario->Location = System::Drawing::Point(40, 210);
            this->lblUsuario->Name = L"lblUsuario";
            this->lblUsuario->Size = System::Drawing::Size(120, 23);
            this->lblUsuario->Text = L"Usuario:";

            // 
            // txtUsuario
            // 
            this->txtUsuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->txtUsuario->Location = System::Drawing::Point(40, 235);
            this->txtUsuario->Name = L"txtUsuario";
            this->txtUsuario->Size = System::Drawing::Size(320, 27);
            this->txtUsuario->MaxLength = 20;

            // 
            // lblContrasena
            // 
            this->lblContrasena->AutoSize = true;
            this->lblContrasena->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblContrasena->ForeColor = System::Drawing::Color::DarkGreen;
            this->lblContrasena->Location = System::Drawing::Point(40, 275);
            this->lblContrasena->Name = L"lblContrasena";
            this->lblContrasena->Size = System::Drawing::Size(120, 23);
            this->lblContrasena->Text = L"Contraseña:";

            // 
            // txtContrasena
            // 
            this->txtContrasena->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->txtContrasena->Location = System::Drawing::Point(40, 300);
            this->txtContrasena->Name = L"txtContrasena";
            this->txtContrasena->PasswordChar = '*';
            this->txtContrasena->Size = System::Drawing::Size(320, 27);
            this->txtContrasena->MaxLength = 30;

            // 
            // chkMostrarContrasena
            // 
            this->chkMostrarContrasena->AutoSize = true;
            this->chkMostrarContrasena->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->chkMostrarContrasena->ForeColor = System::Drawing::Color::Gray;
            this->chkMostrarContrasena->Location = System::Drawing::Point(40, 333);
            this->chkMostrarContrasena->Name = L"chkMostrarContrasena";
            this->chkMostrarContrasena->Size = System::Drawing::Size(150, 23);
            this->chkMostrarContrasena->Text = L"Mostrar contraseña";
            this->chkMostrarContrasena->CheckedChanged += gcnew System::EventHandler(this, &FormLogin::chkMostrarContrasena_CheckedChanged);

            // 
            // btnIngresar
            // 
            this->btnIngresar->BackColor = System::Drawing::Color::ForestGreen;
            this->btnIngresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnIngresar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->btnIngresar->ForeColor = System::Drawing::Color::White;
            this->btnIngresar->Location = System::Drawing::Point(40, 365);
            this->btnIngresar->Name = L"btnIngresar";
            this->btnIngresar->Size = System::Drawing::Size(150, 40);
            this->btnIngresar->Text = L"Ingresar";
            this->btnIngresar->UseVisualStyleBackColor = false;
            this->btnIngresar->Click += gcnew System::EventHandler(this, &FormLogin::btnIngresar_Click);

            // 
            // btnSalir
            // 
            this->btnSalir->BackColor = System::Drawing::Color::IndianRed;
            this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSalir->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->btnSalir->ForeColor = System::Drawing::Color::White;
            this->btnSalir->Location = System::Drawing::Point(210, 365);
            this->btnSalir->Name = L"btnSalir";
            this->btnSalir->Size = System::Drawing::Size(150, 40);
            this->btnSalir->Text = L"Salir";
            this->btnSalir->UseVisualStyleBackColor = false;
            this->btnSalir->Click += gcnew System::EventHandler(this, &FormLogin::btnSalir_Click);

            // 
            // lblIntentos
            // 
            this->lblIntentos->AutoSize = false;
            this->lblIntentos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblIntentos->ForeColor = System::Drawing::Color::Red;
            this->lblIntentos->Location = System::Drawing::Point(40, 410);
            this->lblIntentos->Name = L"lblIntentos";
            this->lblIntentos->Size = System::Drawing::Size(320, 20);
            this->lblIntentos->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblIntentos->Visible = false;

            // 
            // Agregar controles al panel
            // 
            this->panelPrincipal->Controls->Add(this->picLogo);
            this->panelPrincipal->Controls->Add(this->lblTitulo);
            this->panelPrincipal->Controls->Add(this->lblSubtitulo);
            this->panelPrincipal->Controls->Add(this->lblUsuario);
            this->panelPrincipal->Controls->Add(this->txtUsuario);
            this->panelPrincipal->Controls->Add(this->lblContrasena);
            this->panelPrincipal->Controls->Add(this->txtContrasena);
            this->panelPrincipal->Controls->Add(this->chkMostrarContrasena);
            this->panelPrincipal->Controls->Add(this->btnIngresar);
            this->panelPrincipal->Controls->Add(this->btnSalir);
            this->panelPrincipal->Controls->Add(this->lblIntentos);

            // 
            // FormLogin
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::DarkSeaGreen;
            this->ClientSize = System::Drawing::Size(500, 480);
            this->Controls->Add(this->panelPrincipal);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"FormLogin";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Zoológico Salvaje - Iniciar Sesión";
            this->AcceptButton = this->btnIngresar;
            this->CancelButton = this->btnSalir;

            this->panelPrincipal->ResumeLayout(false);
            this->panelPrincipal->PerformLayout();
            this->ResumeLayout(false);
        }

        /// <summary>
        /// Configura estilos adicionales de la interfaz
        /// </summary>
        void ConfigurarEstilos() {
            // Redondear bordes del panel (efecto visual)
            this->panelPrincipal->BorderStyle = System::Windows::Forms::BorderStyle::None;
            
            // Configurar tecla Enter para login
            this->txtContrasena->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FormLogin::txtContrasena_KeyPress);
        }

        /// <summary>
        /// Maneja el evento click del botón Ingresar
        /// </summary>
        void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ usuario = txtUsuario->Text->Trim();
            String^ contrasena = txtContrasena->Text;

            // Validar formato de usuario
            String^ errorUsuario = ServicioAutenticacion::ValidarFormatoUsuario(usuario);
            if (!String::IsNullOrEmpty(errorUsuario)) {
                MessageBox::Show(
                    errorUsuario,
                    L"Error de Validación",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Warning
                );
                txtUsuario->Focus();
                return;
            }

            // Validar formato de contraseña
            String^ errorContrasena = ServicioAutenticacion::ValidarFormatoContrasena(contrasena);
            if (!String::IsNullOrEmpty(errorContrasena)) {
                MessageBox::Show(
                    errorContrasena,
                    L"Error de Validación",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Warning
                );
                txtContrasena->Focus();
                return;
            }

            // Intentar autenticación
            if (servicioAuth->Autenticar(usuario, contrasena)) {
                // Autenticación exitosa
                MessageBox::Show(
                    L"¡Bienvenido al sistema, " + servicioAuth->UsuarioActual->NombreCompleto + "!\n\n" +
                    L"Perfil: " + servicioAuth->UsuarioActual->ObtenerTipoPerfil(),
                    L"Inicio de Sesión Exitoso",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Information
                );

                // Limpiar intentos fallidos
                intentosFallidos = 0;
                lblIntentos->Visible = false;

                // Ocultar formulario de login y mostrar menú principal
                this->Hide();
                this->DialogResult = System::Windows::Forms::DialogResult::OK;
            }
            else {
                // Autenticación fallida
                intentosFallidos++;
                
                if (intentosFallidos >= MAX_INTENTOS) {
                    MessageBox::Show(
                        L"Ha excedido el número máximo de intentos permitidos.\n\n" +
                        L"Por seguridad, la aplicación se cerrará.\n" +
                        L"Contacte al administrador del sistema.",
                        L"Acceso Bloqueado",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Error
                    );
                    Application::Exit();
                }
                else {
                    int intentosRestantes = MAX_INTENTOS - intentosFallidos;
                    
                    MessageBox::Show(
                        L"Usuario o contraseña incorrectos.\n\n" +
                        L"Intentos restantes: " + intentosRestantes.ToString(),
                        L"Error de Autenticación",
                        MessageBoxButtons::OK,
                        MessageBoxIcon::Error
                    );

                    lblIntentos->Text = L"Intentos restantes: " + intentosRestantes.ToString();
                    lblIntentos->Visible = true;
                    
                    // Limpiar contraseña y enfocar
                    txtContrasena->Clear();
                    txtContrasena->Focus();
                }
            }
        }

        /// <summary>
        /// Maneja el evento click del botón Salir
        /// </summary>
        void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
            System::Windows::Forms::DialogResult resultado = MessageBox::Show(
                L"¿Está seguro que desea salir del sistema?",
                L"Confirmar Salida",
                MessageBoxButtons::YesNo,
                MessageBoxIcon::Question
            );

            if (resultado == System::Windows::Forms::DialogResult::Yes) {
                Application::Exit();
            }
        }

        /// <summary>
        /// Maneja el cambio de estado del checkbox para mostrar/ocultar contraseña
        /// </summary>
        void chkMostrarContrasena_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
            if (chkMostrarContrasena->Checked) {
                txtContrasena->PasswordChar = '\0';
            }
            else {
                txtContrasena->PasswordChar = '*';
            }
        }

        /// <summary>
        /// Maneja la tecla Enter en el campo de contraseña
        /// </summary>
        void txtContrasena_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
            if (e->KeyChar == (char)Keys::Enter) {
                btnIngresar_Click(sender, e);
                e->Handled = true;
            }
        }
    };
}

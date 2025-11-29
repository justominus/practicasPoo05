// ZoologicoLogin - Sistema de Login para Zoológico
// Punto de entrada principal de la aplicación

#include "Forms/FormLogin.h"
#include "Forms/FormMenuPrincipal.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace ZoologicoLogin;

/// <summary>
/// Punto de entrada principal de la aplicación
/// </summary>
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    // Habilitar estilos visuales modernos de Windows
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Crear y mostrar el formulario de login
    FormLogin^ formLogin = gcnew FormLogin();
    
    // Bucle principal de la aplicación
    while (true)
    {
        // Mostrar formulario de login
        System::Windows::Forms::DialogResult resultado = formLogin->ShowDialog();
        
        if (resultado == System::Windows::Forms::DialogResult::OK)
        {
            // Login exitoso - mostrar menú principal
            FormMenuPrincipal^ formMenu = gcnew FormMenuPrincipal(formLogin->Servicio);
            System::Windows::Forms::DialogResult resultadoMenu = formMenu->ShowDialog();
            
            // Si el usuario cerró sesión, volver al login
            if (resultadoMenu == System::Windows::Forms::DialogResult::OK)
            {
                // Reiniciar formulario de login
                delete formLogin;
                formLogin = gcnew FormLogin();
                continue;
            }
            else
            {
                // Usuario cerró la aplicación
                break;
            }
        }
        else
        {
            // Usuario canceló o cerró el login
            break;
        }
    }

    return 0;
}

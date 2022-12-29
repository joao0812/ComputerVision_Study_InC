# OpenCV com C++
___
### Documento de estudo para implementação do OpenCV em C++ como VScode no Windows
* Ferramentas necessárias:
    * Cmake 3.25.1;
    * OpenCV 4.5.5
    *  MSVC - Microsoft Visual Studio Community (Para ser o compilador C++ no VScode); 
    *  VScode;

___
### Passo a passo para instalação e configuração
Ao baixar tanto o Cmake quanto o OpenCV, lembre-se de colocar o caminho para a pasta bin de ambos os programas e a pasta lib do OpenCV:
#### 1. Passo 01: Copiando e adicionando o caminho das pastas bin do CMake
    1.1. Ao instalar o CMake, abra a pasta onde o mesmo foi instalado e abra a pasta bin (geralmente o caminho fica *C:\Program Files\CMake\bin*)
    1.2. Copie esse caminho para colocarmos no *Path*
    1.3. Aperte a tecla Windows e digite "Editar as variáveis de ambiente do sistema" e aperte enter
    1.4. Clique no botão "Variáveis de Ambiente.."
    1.5. Em "Variáveis do sistema" selecione *Path* e clique em "Editar"
    1.6. Ao abrir a janela clique em novo e cole o caminho da pasta bin copiado anteriormente
#### 2. Passo 02: Copiando e adicionando o caminho das pastas bin e lib do OpenCV
    2.1. Ao instalar o OpenCV, abra a pasta onde o mesmo foi instalado e abra a pasta bin (geralmente o caminho fica *C:\opencv\build\x64\vc15\bin*)
    2.2. Copie esse caminho para colocarmos no *Path*
    2.3. Aperte a tecla Windows e digite "Editar as variáveis de ambiente do sistema" e aperte enter
    2.4. Clique no botão "Variáveis de Ambiente.."
    2.5. Em "Variáveis do sistema" selecione *Path* e clique em "Editar"
    2.6. Ao abrir a janela clique em novo e cole o caminho da pasta bin copiado anteriormente
    2.7. Para a pasta lib os passos são os mesmos, adicione a pasta lib tal qual a pasta bin foi adicionada (geralmente o caminho fica *C:\opencv\build\x64\vc15\lib*)
#### 3. Passo 03: Configuração do Cmake
    3.1. No VScode baixe as extensões *Cmake* e *Cmake Tools*
    3.2 Abra a pasta do seu projeto clique em "crtl" + "P" digite e selecione "cmake: configure"
    3.3 Selecione a opção *Visual Studio Community 'versão do seu MSVC' amd86_x64*
    3.4 Nomeie seu projeto Cmake, é recomendado colocar o mesmo nome da pasta do projeto inicialmente
    3.5 Selecione *Executavel*
    3.6 Para configurar o OpenCV com CMakeLists.txt, implementamos os seguindos comandos no arquivo CMakeLists.txt:
        - find_package( OpenCV REQUIRED )
        - include_directories(${OpenCV_INCLUDE_DIRS})
        - target_link_libraries(SeuProjeto ${OpenCV_LIBS})
        





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
Ao baixar tanto o Cmake quanto o OpenCV, lembre-se de colocar o caminho para a pasta bin de ambos os programas e a pasta lib do OpenCV, :
- #### Passo 01: Copiando e adicionando o caminho das pastas bin do CMake
    - Ao instalar o CMake, abra a pasta onde o mesmo foi instalado e abra a pasta bin (geralmente o caminho fica *C:\Program Files\CMake\bin*)
    - Copie esse caminho para colocarmos no *Path*
    - Aperte a tecla Windows e digite "Editar as variáveis de ambiente do sistema" e aperte enter
    - Clique no botão "Variáveis de Ambiente.."
    - Em "Variáveis do sistema" selecione *Path* e clique em "Editar"
    - Ao abrir a janela clique em novo e cole o caminho da pasta bin copiado anteriormente
- #### Passo 02: Copiando e adicionando o caminho das pastas bin e lib do OpenCV
    - Ao instalar o OpenCV, abra a pasta onde o mesmo foi instalado e abra a pasta bin (geralmente o caminho fica *C:\opencv\build\x64\vc15\bin*)
    - Copie esse caminho para colocarmos no *Path*
    - Aperte a tecla Windows e digite "Editar as variáveis de ambiente do sistema" e aperte enter
    - Clique no botão "Variáveis de Ambiente.."
    - Em "Variáveis do sistema" selecione *Path* e clique em "Editar"
    - Ao abrir a janela clique em novo e cole o caminho da pasta bin copiado anteriormente
    - Para a pasta lib os passos são os mesmos, adicione a pasta lib tal qual a pasta bin foi adicionada (geralmente o caminho fica *C:\opencv\build\x64\vc15\lib*)




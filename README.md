Instruções de uso
Para utilizar o software desenvolvido, siga os passos abaixo:

1°: Clone o repositório para o seu computador.

Abra o projeto com o VSCode e, ao executar, os arquivos de compilação serão gerados automaticamente.

Caso os arquivos de compilação não sejam gerados, crie uma pasta chamada build e execute o seguinte comando dentro dela:

bash
Copiar
Editar
cmake ..
O comando acima irá gerar os arquivos de compilação necessários.

2°: Compile o código utilizando a extensão Raspberry Pi Pico no VSCode.

A partir desse ponto, o firmware já estará compilado e pronto para uso.

Execução no ambiente de simulação Wokwi
Para rodar o firmware no ambiente de simulação, você precisará da extensão Wokwi instalada no VSCode, além de ter configurado sua licença.

Com os requisitos acima atendidos, basta clicar no arquivo diagram.json, e a simulação abrirá automaticamente com o esquemático pronto.

Clique no botão de play, no canto superior esquerdo, e simule!

Execução no Raspberry Pi Pico
Para executar o firmware diretamente no Raspberry Pi Pico, siga os passos abaixo:

Coloque o seu Raspberry Pi Pico em modo de bootsel:

Mantenha pressionado o botão BOOTSEL e conecte o dispositivo ao computador via USB. O Raspberry Pi aparecerá como um dispositivo de armazenamento.
Copie o arquivo .uf2 gerado pela compilação para o Raspberry Pi Pico (ele aparecerá como um dispositivo USB externo com o nome de RPI-RP2).

O firmware começará a rodar automaticamente no Raspberry Pi Pico.

Comandos disponíveis
Aqui estão os comandos que você pode usar no terminal para controlar os LEDs e o buzzer:

verde: Acende o LED verde.
azul: Acende o LED azul.
vermelho: Acende o LED vermelho.
ledsON: Acende todos os LEDs.
ledsOFF: Apaga todos os LEDs.
buzzer: Ativa o buzzer por 1 segundo.
Conclusão
Com isso, você pode testar o funcionamento do sistema de LEDs e buzzer diretamente no seu Raspberry Pi Pico ou em ambiente de simulação no Wokwi.

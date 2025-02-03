# Embarcatech U4C5-T1

Este código implementa a Tarefa 1 da atividade da Unidade 4, capítulo 5.
Neste exercício, um timer é responsável por alterar o status de um semáforo a cada 3 segundos alterando a cor do sinal a cada 3 segundos de forma totalmente independente do loop principal.
Enquanto o sinal é atualizado, o loop principal fica imprimindo o tempo de execução a cada 1 segundo.

## Leds configurados

| Tecla    | Funcionalidade |
| -------- | -------------- |
| Vermelho | Gpio 11        |
| Amarelo  | Gpio 12        |
| Verde    | Gpio 13        |

## Hardware 🛠️

- Microcontrolador RP2040 (Raspberry Pi Pico).
- Leds coloridos

## Software 💻

- **SDK do Raspberry Pi Pico:** O SDK (Software Development Kit) do Pico, que inclui as bibliotecas e ferramentas necessárias para desenvolver e compilar o código. [Instruções de instalação](https://www.raspberrypi.com/documentation/pico/getting-started/)
- **CMake:** Um sistema de construção multiplataforma usado para gerar os arquivos de construção do projeto.
- **Compilador C/C++:** Um compilador C/C++ como o GCC (GNU Compiler Collection).
- **Git:** (Opcional) Para clonar o repositório do projeto.

### O código está dividido em vários arquivos para melhor organização:

- **`U4T5-T1.C`**: Código com a função de loop principal: lê as teclas e chama as funções de animação.
- **`CMakeLists.txt`:** Define a estrutura do projeto para o CMake.
- **`diagram.json`:** Diagramas de conexões.
  |

## Como Compilar e Executar ⚙️

1. **Instale o SDK do Raspberry Pi Pico:** Siga as instruções no site oficial do Raspberry Pi.
2. **Clone este repositório:** `git clone git@github.com:klebersm/embarcatech-U4C5-T1.git`
3. **Navegue até o diretório do projeto:** `cd Embarcatech-U4C5-T1`
4. **Compile o projeto:** `cmake -B build && cmake --build build`
5. **Copie para o Pico:** Copie o arquivo `U4C5-T1.uf2` da pasta `build` (gerada após a compilação) para o Raspberry Pi Pico. O programa iniciará automaticamente.

## Inicialização do GPIO 🔄

Os leds foram inicializados fazendo o uso de máscara para tornar o código mais enxuto. Um valor inicial de máscara é criado setando o bit equivalente a cada led e depois disso esta máscara é utilizada nas funções de configuração de GPIO.

```
  uint ledMask = (0x01 << LED_VERMELHO) | (0x01 << LED_AMARERELO) | (0x01 << LED_VERDE);
  gpio_init_mask(ledMask);
  gpio_set_dir_out_masked(ledMask);
```

## Temporizador ⏱️

Um temporizador é criado para chamar a função de callback a cada 3 segundos, atualizando o status do sistema e ligando o led correspondente.

```
  struct repeating_timer timer;
  add_repeating_timer_ms(3000, repeat_callback, NULL, &timer);
```

## 📞 Contato

- 👤 **Autor**: Kleber Marçal

- 📧 **E-mail**:kleber.sm@gmail.com

---

# 📌 Controle de Servo Motor e LED com Raspberry Pi Pico W

## 📖 Sobre o Projeto
Este projeto demonstra o **uso do PWM no Raspberry Pi Pico W** para controlar um **servomotor e um LED azul** simultaneamente. O sistema faz com que o **servo se mova suavemente entre 0° e 180°**, ajustando o brilho do LED de acordo com o ângulo do servo.

## 🎯 Objetivos do Projeto
✅ Explorar o funcionamento do **PWM** no RP2040.  
✅ Integrar e controlar um **servomotor e um LED** via PWM.  
✅ Criar um movimento suave do servo com **pequenos incrementos no ciclo ativo**.  
✅ Ajustar o brilho do LED proporcionalmente ao movimento do servo.  
✅ Simular e testar o projeto no **Wokwi**.  
✅ Realizar experimentos práticos utilizando a **ferramenta BitDogLab**.  

## 🛠️ Componentes Utilizados
- **Microcontrolador:** Raspberry Pi Pico W  
- **Servomotor padrão** (wokwi-servo) – Conectado à **GPIO 22**  
- **LED Azul** – Conectado à **GPIO 12**  
- **Resistor de 330Ω** – Limitador de corrente para o LED  

## 🚀 Configuração e Funcionamento

### 1. Configuração do PWM na GPIO 22
- A frequência do PWM é configurada para **50Hz**, resultando em um período de **20ms**.  
- O ciclo ativo do PWM varia para ajustar a posição do servo.  

### 2. Ajuste de Posições do Servomotor
O sistema ajusta a flange do servo para três posições específicas:

| Ângulo | Tempo Ativo | Ciclo de Trabalho |
|--------|------------|-------------------|
| **0°** | 500µs | 2.5% |
| **90°** | 1470µs | 7.35% |
| **180°** | 2400µs | 12% |

- **Movimento inicial do servo**:
  - O servo é movido para **180°**, onde permanece por **5 segundos**.
  - O servo é movido para **90°**, onde permanece por **5 segundos**.
  - O servo é movido para **0°**, onde permanece por **5 segundos**.

### 3. Movimento Suave entre 0° e 180°
- Após a movimentação inicial, o servo oscila continuamente entre **0° e 180°**.  
- Para garantir suavidade, o ciclo ativo do PWM é incrementado/decrementado em **5µs** por iteração.  
- Um atraso de **10ms** é aplicado entre os ajustes para proporcionar uma transição suave.

### 4. Controle do LED Azul com PWM
- O LED azul está conectado à **GPIO 12** e também é controlado via PWM.  
- O brilho do LED é ajustado proporcionalmente ao **ângulo do servomotor**.

## 🛠️ Configuração do Hardware
1. **Conectar os componentes ao Raspberry Pi Pico W** conforme a seguinte tabela:

| Componente | GPIO |
|------------|------|
| Servomotor | 22 |
| LED Azul | 12 |
| Resistor (330Ω) | Em série com o LED |

2. **Configurar PWM no código** para operar a **50Hz**.  
3. **Definir os ciclos ativos do servo** para posições de **0°, 90° e 180°**.  
4. **Fazer o LED variar o brilho** proporcionalmente ao ângulo do servo.   

## 🔬 Experimento com a Ferramenta BitDogLab
Para validar o comportamento do sistema, foi realizado um experimento utilizando a **BitDogLab**, onde se observou:
1. **O comportamento do LED RGB (GPIO 12)** variando sua intensidade de brilho conforme o ângulo do servomotor.
2. **O movimento do servo** ficou mais fluído devido ao ajuste suave de PWM.
3. **Sincronização entre LED e servo**, onde o LED atingia o brilho máximo ao servo estar em 180° e o brilho mínimo ao servo estar em 0°.

## 📸 Demonstração do Projeto
📹 **[Assista ao vídeo demonstrativo](https://drive.google.com/file/d/1yfxOpi2ARpixe9Zek_S0fhwNa1X59_H4)**  

## 📜 Licença
Este projeto é de código aberto e pode ser usado livremente para fins educacionais e experimentação.
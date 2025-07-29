# คู่มือเริ่มต้นการเขียนโปรแกรม ESP32 🚀

## 🎯 สำหรับผู้เริ่มต้นหรือไม่เคยเขียนโปรแกรม

### การเรียนรู้แบบขั้นเป็นตอนของเรา:
1. **📖 เข้าใจพื้นฐาน** - อ่านคู่มือนี้ก่อน
2. **👶 เริ่มง่ายๆ** - ทำโปรเจค 1-4 (ระดับประถม)
3. **🔥 ยกระดับ** - ทำโปรเจค 5-8 (ระดับสูงขึ้น)
4. **🎓 เป็นโปรแกรมเมอร์** - สร้างของตัวเอง!

---

## 📚 บทที่ 1: ESP32 และการเขียนโปรแกรม

### 🤔 ESP32 คืออะไร?
ESP32 เป็น "สมองกลเล็กๆ" ที่สามารถ:
- 🧮 **คำนวณเลข** - เหมือนเครื่องคิดเลข
- 📶 **เชื่อมต่อ WiFi** - เข้าเนตได้
- 💡 **ควบคุมไฟ LED** - เปิด-ปิดได้
- 📊 **อ่านเซ็นเซอร์** - วัดอุณหภูมิ, แสง

### 🔤 ภาษา C คืออะไร?
ภาษา C เป็น "ภาษา" ที่เราใช้สื่อสารกับ ESP32:
```c
// นี่คือการบอก ESP32 ว่า "1 + 1"
int result = 1 + 1;

// นี่คือการบอก ESP32 ว่า "แสดงผลลัพธ์"
printf("ผลลัพธ์: %d", result);
```

### 🏠 ทำไมต้องใช้ Docker?
Docker เหมือน "บ้านสำเร็จรูป" ที่มีเครื่องมือครบพร้อมใช้:
- ✅ ไม่ต้องติดตั้งซับซ้อน  
- ✅ ทำงานเหมือนกันทุกเครื่อง
- ✅ มีทุกอย่างที่ต้องการแล้ว

---

## �️ บทที่ 2: การเตรียมเครื่องมือ

### ✅ สิ่งที่ต้องมี:
- [ ] **Docker** - ตัวจัดการ environment (สำคัญที่สุด!)
- [ ] **VS Code** - โปรแกรมแก้ไขโค้ด (แนะนำ)
- [ ] **Git** - จัดการโค้ด (ถ้าต้องการ)

### 🔍 ตรวจสอบ Docker

**Windows:**
```cmd
docker --version
```

**Mac/Linux:**
```bash
docker --version
```

**ควรเห็นผลลัพธ์คล้ายๆ นี้:**
```
Docker version 20.x.x
docker-compose version 1.x.x
```

### 2.3 เริ่มต้นโปรเจค

1. **สร้าง Container**
```bash
docker-compose up -d
```

2. **เข้าสู่ Container**
```bash
docker exec -it esp32-lab4 bash
```

3. **ตั้งค่า Environment**
```bash
. $IDF_PATH/export.sh
```

4. **ตรวจสอบการติดตั้ง**
```bash
idf.py --version
```

---

## 📖 บทที่ 3: โครงสร้างโปรแกรม C บน ESP32

### 3.1 โครงสร้างไฟล์โปรเจค
```
project/
├── CMakeLists.txt          # การตั้งค่า build system
├── main/
│   ├── CMakeLists.txt      # การตั้งค่า main component
│   └── main.c              # ไฟล์โปรแกรมหลัก
├── components/             # ไลบรารีเสริม (ถ้ามี)
└── sdkconfig               # การตั้งค่าโปรเจค
```

### 3.2 โครงสร้างโปรแกรม C พื้นฐาน

```c
// 1. Include Libraries
#include <stdio.h>              // สำหรับ printf
#include "freertos/FreeRTOS.h"  // Real-time OS
#include "freertos/task.h"      // Task management
#include "esp_log.h"            // Logging system

// 2. Define Constants
#define LED_PIN 2
#define DELAY_MS 1000

// 3. Global Variables
static const char *TAG = "MAIN";
int counter = 0;

// 4. Function Declarations
void setup_hardware(void);
void main_loop(void);

// 5. Function Implementations
void setup_hardware(void) {
    // ตั้งค่าฮาร์ดแวร์ที่นี่
    ESP_LOGI(TAG, "Hardware setup completed");
}

void main_loop(void) {
    // โค้ดหลักที่รันซ้ำๆ
    ESP_LOGI(TAG, "Loop iteration: %d", counter++);
    vTaskDelay(DELAY_MS / portTICK_PERIOD_MS);
}

// 6. Main Function
void app_main(void) {
    ESP_LOGI(TAG, "Starting application");
    
    setup_hardware();
    
    while(1) {
        main_loop();
    }
}
```

### 3.3 อธิบายส่วนประกอบ

1. **Include Libraries**: นำเข้าไลบรารีที่จำเป็น
2. **Define Constants**: กำหนดค่าคงที่
3. **Global Variables**: ตัวแปรที่ใช้ทั่วโปรแกรม
4. **Function Declarations**: ประกาศฟังก์ชัน
5. **Function Implementations**: เขียนฟังก์ชัน
6. **Main Function**: ฟังก์ชันหลัก `app_main()`

---

## 🔧 บทที่ 4: การทำงานกับตัวเลขและการคำนวณ

### 4.1 ประเภทข้อมูลพื้นฐาน

```c
// จำนวนเต็ม
int whole_number = 42;          // 32-bit signed integer
uint32_t positive_number = 100; // 32-bit unsigned integer
int8_t small_number = -128;     // 8-bit signed integer

// จำนวนทศนิยม
float decimal_number = 3.14f;   // 32-bit floating point
double precise_number = 3.14159; // 64-bit floating point

// ตัวอักษร
char letter = 'A';              // Single character
char text[] = "Hello ESP32";    // String (array of char)

// บูลีน
bool is_ready = true;           // true หรือ false
```

### 4.2 การคำนวณพื้นฐาน

```c
void basic_arithmetic_demo(void) {
    float a = 10.5;
    float b = 3.2;
    
    // การบวก
    float sum = a + b;
    ESP_LOGI(TAG, "%.2f + %.2f = %.2f", a, b, sum);
    
    // การลบ
    float difference = a - b;
    ESP_LOGI(TAG, "%.2f - %.2f = %.2f", a, b, difference);
    
    // การคูณ
    float product = a * b;
    ESP_LOGI(TAG, "%.2f * %.2f = %.2f", a, b, product);
    
    // การหาร
    float quotient = a / b;
    ESP_LOGI(TAG, "%.2f / %.2f = %.2f", a, b, quotient);
    
    // เศษจากการหาร (เฉพาะจำนวนเต็ม)
    int x = 10, y = 3;
    int remainder = x % y;
    ESP_LOGI(TAG, "%d %% %d = %d", x, y, remainder);
}
```

### 4.3 การใช้ฟังก์ชันคณิตศาสตร์

```c
#include <math.h>

void math_functions_demo(void) {
    float number = 16.0;
    
    // รากที่สอง
    float sqrt_result = sqrtf(number);
    ESP_LOGI(TAG, "sqrt(%.2f) = %.2f", number, sqrt_result);
    
    // ยกกำลัง
    float power_result = powf(2.0, 3.0);
    ESP_LOGI(TAG, "2^3 = %.2f", power_result);
    
    // ค่าสัมบูรณ์
    float abs_result = fabsf(-5.5);
    ESP_LOGI(TAG, "abs(-5.5) = %.2f", abs_result);
    
    // ปัดเศษ
    float round_result = roundf(3.7);
    ESP_LOGI(TAG, "round(3.7) = %.2f", round_result);
}
```

---

## 🔄 บทที่ 5: การควบคุมการทำงาน (Control Flow)

### 5.1 เงื่อนไข (if-else)

```c
void condition_demo(void) {
    int temperature = 25;
    
    if (temperature > 30) {
        ESP_LOGI(TAG, "อากาศร้อน");
    } else if (temperature > 20) {
        ESP_LOGI(TAG, "อากาศปกติ");
    } else {
        ESP_LOGI(TAG, "อากาศเย็น");
    }
    
    // Ternary operator
    char *status = (temperature > 25) ? "ร้อน" : "เย็น";
    ESP_LOGI(TAG, "สถานะ: %s", status);
}
```

### 5.2 ลูป (Loops)

```c
void loop_demo(void) {
    ESP_LOGI(TAG, "=== For Loop ===");
    // For loop
    for (int i = 1; i <= 5; i++) {
        ESP_LOGI(TAG, "Count: %d", i);
    }
    
    ESP_LOGI(TAG, "=== While Loop ===");
    // While loop
    int counter = 1;
    while (counter <= 3) {
        ESP_LOGI(TAG, "While count: %d", counter);
        counter++;
    }
    
    ESP_LOGI(TAG, "=== Do-While Loop ===");
    // Do-while loop
    int num = 1;
    do {
        ESP_LOGI(TAG, "Do-while: %d", num);
        num++;
    } while (num <= 2);
}
```

### 5.3 Switch-Case

```c
void switch_demo(void) {
    int day = 3;
    
    switch (day) {
        case 1:
            ESP_LOGI(TAG, "จันทร์");
            break;
        case 2:
            ESP_LOGI(TAG, "อังคาร");
            break;
        case 3:
            ESP_LOGI(TAG, "พุธ");
            break;
        default:
            ESP_LOGI(TAG, "วันอื่นๆ");
            break;
    }
}
```

---

## 📊 บทที่ 6: การทำงานกับ Array และ Functions

### 6.1 Array (อาร์เรย์)

```c
void array_demo(void) {
    // การประกาศ array
    int numbers[5] = {10, 20, 30, 40, 50};
    float temperatures[] = {25.5, 26.0, 24.8, 27.2};
    
    // การเข้าถึงข้อมูลใน array
    ESP_LOGI(TAG, "First number: %d", numbers[0]);
    ESP_LOGI(TAG, "Last number: %d", numbers[4]);
    
    // การวนลูปผ่าน array
    ESP_LOGI(TAG, "All numbers:");
    for (int i = 0; i < 5; i++) {
        ESP_LOGI(TAG, "numbers[%d] = %d", i, numbers[i]);
    }
    
    // หาขนาดของ array
    int array_size = sizeof(numbers) / sizeof(numbers[0]);
    ESP_LOGI(TAG, "Array size: %d", array_size);
}
```

### 6.2 Functions (ฟังก์ชัน)

```c
// ฟังก์ชันที่ไม่รับพารามิเตอร์และไม่คืนค่า
void say_hello(void) {
    ESP_LOGI(TAG, "สวัสดี ESP32!");
}

// ฟังก์ชันที่รับพารามิเตอร์และคืนค่า
int add_numbers(int a, int b) {
    return a + b;
}

// ฟังก์ชันที่รับ array เป็นพารามิเตอร์
float calculate_average(float numbers[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

void function_demo(void) {
    // เรียกใช้ฟังก์ชัน
    say_hello();
    
    int result = add_numbers(5, 3);
    ESP_LOGI(TAG, "5 + 3 = %d", result);
    
    float temps[] = {25.0, 26.5, 24.8, 27.0};
    float avg = calculate_average(temps, 4);
    ESP_LOGI(TAG, "Average temperature: %.2f", avg);
}
```

---

## ⚠️ บทที่ 7: การจัดการข้อผิดพลาด

### 7.1 การตรวจสอบค่าที่รับเข้ามา

```c
float safe_divide(float a, float b) {
    if (b == 0.0) {
        ESP_LOGE(TAG, "Error: Division by zero!");
        return 0.0;
    }
    return a / b;
}

int safe_array_access(int array[], int size, int index) {
    if (index < 0 || index >= size) {
        ESP_LOGE(TAG, "Error: Array index out of bounds!");
        return -1;  // Error code
    }
    return array[index];
}
```

### 7.2 การใช้ Return Codes

```c
typedef enum {
    CALC_OK = 0,
    CALC_ERROR_DIV_ZERO,
    CALC_ERROR_INVALID_INPUT
} calc_result_t;

calc_result_t safe_calculation(float a, float b, float *result) {
    if (result == NULL) {
        return CALC_ERROR_INVALID_INPUT;
    }
    
    if (b == 0.0) {
        return CALC_ERROR_DIV_ZERO;
    }
    
    *result = a / b;
    return CALC_OK;
}

void error_handling_demo(void) {
    float result;
    calc_result_t status = safe_calculation(10.0, 2.0, &result);
    
    switch (status) {
        case CALC_OK:
            ESP_LOGI(TAG, "Result: %.2f", result);
            break;
        case CALC_ERROR_DIV_ZERO:
            ESP_LOGE(TAG, "Cannot divide by zero");
            break;
        case CALC_ERROR_INVALID_INPUT:
            ESP_LOGE(TAG, "Invalid input parameter");
            break;
    }
}
```

---

## 🔍 บทที่ 8: การ Debug และ Monitoring

### 8.1 การใช้ ESP_LOG

```c
void logging_demo(void) {
    // ระดับ Log ต่างๆ
    ESP_LOGE(TAG, "This is an ERROR message");    // สีแดง
    ESP_LOGW(TAG, "This is a WARNING message");   // สีเหลือง
    ESP_LOGI(TAG, "This is an INFO message");     // สีเขียว
    ESP_LOGD(TAG, "This is a DEBUG message");     // สีขาว
    ESP_LOGV(TAG, "This is a VERBOSE message");   // สีเทา
    
    // Log พร้อมตัวแปร
    int value = 42;
    float temperature = 25.6;
    ESP_LOGI(TAG, "Value: %d, Temperature: %.1f°C", value, temperature);
}
```

### 8.2 การวัดเวลาการทำงาน

```c
#include "esp_timer.h"

void performance_measurement_demo(void) {
    // เริ่มนับเวลา
    int64_t start_time = esp_timer_get_time();
    
    // ทำงานที่ต้องการวัด
    for (int i = 0; i < 1000; i++) {
        volatile float result = sqrtf(i);  // ป้องกัน compiler optimization
    }
    
    // หยุดนับเวลา
    int64_t end_time = esp_timer_get_time();
    int64_t duration = end_time - start_time;
    
    ESP_LOGI(TAG, "Operation took %lld microseconds", duration);
}
```

### 8.3 การตรวจสอบ Memory

```c
void memory_info_demo(void) {
    size_t free_heap = esp_get_free_heap_size();
    size_t min_free_heap = esp_get_minimum_free_heap_size();
    
    ESP_LOGI(TAG, "Free heap: %u bytes", free_heap);
    ESP_LOGI(TAG, "Minimum free heap: %u bytes", min_free_heap);
}
```

---

## 🎯 บทที่ 9: แบบฝึกหัดและโครงงาน

### แบบฝึกหัดที่ 1: เครื่องคิดเลขพื้นฐาน
```c
void calculator_exercise(void) {
    float a = 15.5, b = 4.2;
    
    ESP_LOGI(TAG, "=== Calculator Demo ===");
    ESP_LOGI(TAG, "Numbers: %.2f and %.2f", a, b);
    
    // TODO: เพิ่มการคำนวณ +, -, *, /
    // TODO: เพิ่มการตรวจสอบหารด้วยศูนย์
}
```

### แบบฝึกหัดที่ 2: สถิติของตัวเลข
```c
void statistics_exercise(void) {
    float numbers[] = {2.5, 8.1, 3.7, 9.2, 1.4, 6.8, 4.3};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    
    // TODO: หาค่าเฉลี่ย
    // TODO: หาค่าสูงสุดและต่ำสุด
    // TODO: หาค่ามัธยฐาน
}
```

### แบบฝึกหัดที่ 3: ตรวจสอบจำนวนเฉพาะ
```c
bool is_prime(int number) {
    // TODO: เขียนฟังก์ชันตรวจสอบจำนวนเฉพาะ
    return false;
}

void prime_number_exercise(void) {
    for (int i = 1; i <= 20; i++) {
        if (is_prime(i)) {
            ESP_LOGI(TAG, "%d is prime", i);
        }
    }
}
```

---

## ✅ บทที่ 10: Checklist และการทดสอบ

### 10.1 Pre-Lab Checklist
- ✅ ติดตั้ง Docker และ docker-compose เรียบร้อย
- ✅ ดาวน์โหลด ESP-IDF Docker image แล้ว
- ✅ สร้างโปรเจคและไฟล์ต่างๆ ครบถ้วน
- ✅ ทดสอบ build โปรเจคสำเร็จ

### 10.2 During Lab Checklist
- [ ] เข้าใจโครงสร้างโปรแกรม C บน ESP32
- [ ] สามารถใช้ตัวแปรและการคำนวณได้
- [ ] เข้าใจการใช้ if-else และ loops
- [ ] สามารถสร้างและใช้ functions ได้
- [ ] รู้จักการจัดการข้อผิดพลาด

### 10.3 Post-Lab Checklist
- [ ] โปรแกรมทำงานได้ถูกต้องบน QEMU
- [ ] ผ่านการทดสอบทุก test cases
- [ ] เขียนรายงานครบถ้วน
- [ ] ส่งงานตามเวลาที่กำหนด

---

## 📝 บทที่ 11: เทคนิคการเขียนโปรแกรมที่ดี

### 11.1 การตั้งชื่อตัวแปรและฟังก์ชัน
```c
// ❌ ไม่ดี
int a, b, c;
void func1(void);

// ✅ ดี
int temperature_celsius;
int humidity_percentage;
void calculate_average_temperature(void);
```

### 11.2 การเขียน Comments
```c
// ✅ Comment ที่ดี
/**
 * คำนวณค่าเฉลี่ยของตัวเลขใน array
 * @param numbers: array ของตัวเลข
 * @param count: จำนวนสมาชิกใน array
 * @return: ค่าเฉลี่ย หรือ 0 ถ้า count = 0
 */
float calculate_average(float numbers[], int count) {
    if (count == 0) {
        return 0.0;  // ป้องกันการหารด้วยศูนย์
    }
    
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    
    return sum / count;
}
```

### 11.3 การจัดระเบียบโค้ด
```c
// 1. Includes
#include <stdio.h>
#include "esp_log.h"

// 2. Defines
#define MAX_NUMBERS 100
#define TAG "CALCULATOR"

// 3. Type definitions
typedef struct {
    float value;
    bool is_valid;
} calculation_result_t;

// 4. Global variables
static int global_counter = 0;

// 5. Function prototypes
float add(float a, float b);
void display_result(float result);

// 6. Function implementations
// ...

// 7. Main function
void app_main(void) {
    // ...
}
```

---

## 🎓 สรุป

### สิ่งที่เรียนรู้ในบทนี้:
1. **พื้นฐานไมโครคอนโทรลเลอร์**: ESP32 และการใช้งาน
2. **โครงสร้างโปรแกรม**: การจัดระเบียบโค้ด C
3. **ตัวแปรและการคำนวณ**: ประเภทข้อมูลและการคำนวณ
4. **Control Flow**: if-else, loops, switch-case
5. **Functions และ Arrays**: การสร้างและใช้งาน
6. **Error Handling**: การจัดการข้อผิดพลาด
7. **Debugging**: การใช้ ESP_LOG และการวัดประสิทธิภาพ

### ขั้นตอนต่อไป:
1. ฝึกทำแบบฝึกหัดในแต่ละบท
2. ทดลองแก้ไขโค้ดและดูผลลัพธ์
3. อ่านเอกสาร ESP-IDF เพิ่มเติม
4. เรียนรู้การใช้งาน Hardware peripherals

**Happy Coding! 🚀**

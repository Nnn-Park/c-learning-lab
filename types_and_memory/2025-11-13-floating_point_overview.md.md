# 🔢 Floating-Point Representation — Research Notes
---
## 🧠 오늘의 질문들 (Why I studied this)
- 왜 64비트 환경에서 long double이 16바이트가 아닐까?  
- 왜 x86-64에서는 long double이 16바이트인데 ARM64(macOS)에서는 8바이트일까?  
- CPU 비트수와 자료형의 크기는 무슨 관계가 있을까?  
- float, double, long double의 정밀도가 실제 연산에서 어떻게 차이날까?

---

## 1. float / double / long double — 플랫폼별 크기 비교

| 타입 | C 표준 최소 | macOS (ARM64) | x86-64 (GCC) |
|------|-------------|----------------|---------------|
| float | 4 byte | 4 byte | 4 byte |
| double | 8 byte | 8 byte | 8 byte |
| long double | ≥ 8 byte | **8 byte** | **16 byte** |

📌 **핵심 포인트**  
- ARM64(macOS)는 IEEE754 double만 사용 → long double = double  
- x86-64는 x87 80-bit 확장정밀도 사용 → 16바이트 패딩 저장

---

## 2. x86-64의 long double = 16바이트인 이유  

x87 FPU는 다음과 같은 80-bit 확장정밀도를 지원한다:

- sign: 1bit  
- exponent: 15bit  
- mantissa: 64bit  

메모리 alignment 때문에 80bit 값을 **16바이트로 저장**한다.

---

## 3. ARM64(macOS)는 왜 8바이트인가?

- ARM64 ABI(AAPCS64)는 80-bit 확장정밀도를 사용하지 않음  
- NEON 기반 64bit double만 기본 지원  
→ long double이 double과 완전히 동일

---

## 4. 정밀도 누적 실험에서 관찰

실험 파일: `floating_point_precision_demo.c`

- float는 누적 오차가 가장 크다  
- double은 15자리 정확도로 float보다 안정적  
- ARM64의 long double은 double과 동일한 결과  
- x86-64에서는 long double이 double보다 더 정밀함

---

## 📌 요약

- CPU 비트수는 실수형 크기와 무관  
- **ABI + 컴파일러**가 결정  
- 실험을 통해 이론과 실제 동작 차이를 직접 확인함

---

## 📎 다음 단계
- 구조체 padding/alignment 실험  
- integer overflow 관찰  
- hexdump로 실수 비트 패턴 보기  
- x86-64에서의 long double 비교 실험
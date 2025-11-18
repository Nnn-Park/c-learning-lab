# 1️⃣ [floating_point_overview.md](../types_and_memory/floating_point_overview.md)

# 🔢 Floating-Point Representation — Research Notes

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

---

## 2. x86-64의 long double = 16바이트인 이유
- x87 FPU는 80-bit 확장 정밀도 사용
- alignment 때문에 80bit 값을 16 bytes로 저장

---

## 3. ARM64(macOS)는 왜 8바이트인가?
- ARM64의 NEON은 double(64bit) 기반
- 확장 정밀도 미지원 → long double = double

---

## 4. 정밀도 누적 실험 결과
- float는 누적 오차가 가장 큼
- double은 비교적 안정적
- macOS long double = double과 동일 동작
- x86-64 long double이 가장 정밀함

---

## 📎 결론
- CPU 비트수는 실수 자료형 크기를 결정하지 않음
- ABI와 컴파일러가 long double의 크기를 정의함

---

# 3️⃣ [floating_point_precision_demo.c](../types_and_memory/floating_point_precision_demo.c)

```c
#include <stdio.h>

int main() {
    float f = 0.0;
    double d = 0.0;
    long double ld = 0.0;

    for (int i = 0; i < 100; i++) {
        f += 0.01;
        d += 0.01;
        ld += 0.01;
    }

    printf("float:       %.20f\n", f);
    printf("double:      %.20lf\n", d);
    printf("long double: %.20Lf\n", ld);
}
```

---

# 4️⃣ [floating_point_bit_pattern_demo.c](../types_and_memory/floating_point_bit_pattern_demo.c)

```c
#include <stdio.h>

void print_bytes(void *ptr, size_t size) {
    unsigned char *p = ptr;
    for (size_t i = 0; i < size; i++)
        printf("%02X ", p[i]);
    printf("\n");
}

int main() {
    float f = 0.1f;
    double d = 0.1;
    long double ld = 0.1L;

    printf("float bytes: ");
    print_bytes(&f, sizeof(f));

    printf("double bytes: ");
    print_bytes(&d, sizeof(d));

    printf("long double bytes: ");
    print_bytes(&ld, sizeof(ld));
}
```
부동소수점 값이 메모리에 저장될 때 실제 bit pattern이 어떻게 구성되는지 직접 확인하기 위해, 메모리를 byte 단위로 덤프하는 실험 코드를 작성함. 이 코드로 float/double/long double의 내부 구조 차이와 IEEE-754 표현 방식의 한계(0.1이 binary로 정확히 표현되지 않음)를 눈으로 확인할 수 있었다.

---

# 5️⃣ 브랜치 전략 요약 ([git_branching_and_workflow.md](git_branching_and_workflow.md))

- **main** → 정리된 문서 + 안정적인 코드  
- **experiment/&lt;topic&gt;** → 실험 코드  
- **notes/&lt;date-topic&gt;** → 연구 노트 작성 브랜치  
- **refactor/&lt;area&gt;** → 폴더 구조/코드 대규모 변경  

---

# 6️⃣ [commit_conventions.md](commit_conventions.md) 요약

| Prefix | 의미 |
|--------|------|
| feat | 기능 추가 |
| docs | 문서/정리 |
| note | 연구노트 |
| exp | 실험 코드 |
| fix | 버그 수정 |
| refactor | 구조 정리 |
| chore | 설정/기타 |

---

# 7️⃣ Git 기본 명령 세트

```bash
git status
git add .
git commit -m "message"
git push
git checkout -b experiment/<topic>
git diff --cached
git log --oneline
```

---

# 8️⃣ 오늘 최종 커밋 메시지

```
docs: floating point 정리 업데이트 및 precision 실험 코드 추가
note: git workflow와 commit convention 연구노트 추가
```

---

# 🎯 Today Summary

- 실수 타입 및 long double 동작 완벽 정리  
- precision 실험 코드 작성  
- 비트패턴 실험 코드 템플릿 추가  
- notes/ 구조 구축  
- commit 규칙 + branch 전략 수립  
- repo 기반 구조 확립  

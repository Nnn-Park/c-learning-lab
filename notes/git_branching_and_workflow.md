## 🧠 오늘의 질문들 (Why I studied this)
- 개인 공부용 레포인데 브랜치를 쓰는 게 좋을까?
- main 하나로만 가면 어떤 문제가 생길까?
- experiment/ 같은 브랜치 네이밍은 어떻게 쓰는 걸까?
- Git 브랜치와 내 "연구 로그" 스타일을 어떻게 연결할 수 있을까?

---

# 🌿 C-Learning-Lab 브랜치 전략 정리

이 레포는 단순 예제 모음이 아니라  
**개념 → 실험 → 정리**가 반복되는 개인 연구실이기 때문에  
브랜치를 적당히 나눠 쓰는 쪽이 더 잘 맞는다.

---

## 1. 브랜치 종류

### `main`
- 항상 "정리된 상태"를 유지하는 브랜치
- README, 정리 완료된 md, 안정적인 코드가 들어감

### `experiment/<topic>`
- 실험용 브랜치
- 예:  
  - `experiment/fp-precision`  
  - `experiment/pointer-arith`  
  - `experiment/memory-alignment`

### `notes/<date>-<topic>`
- 연구 노트나 글을 작성할 때 사용하는 브랜치
- 예:  
  - `notes/2025-11-13-floating-point`  
  - `notes/2025-11-20-pointers`

### `refactor/<area>`
- 폴더 구조/파일 이름/코드 정리 등의 개편 작업에 사용
- 예:  
  - `refactor/types-and-memory-layout`

---

## 2. 기본 워크플로우

### 2.1 새 실험 시작

```bash
git checkout main
git pull
git checkout -b experiment/<topic>
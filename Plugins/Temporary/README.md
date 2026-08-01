# Temporary Plugin

## 소개

`Temporary`는 Unreal Engine의 플러그인과 모듈 구조를 학습하기 위해 수동으로 제작한 Runtime 플러그인입니다.

플러그인 모듈의 시작과 종료 시점을 로그로 확인할 수 있으며, `ATemporaryActor`를 기반으로 블루프린트를 만들어 월드에서 실행할 수 있습니다.

## 개발 환경

- Unreal Engine 5.5
- C++ 프로젝트
- 모듈 타입: `Runtime`
- 로딩 시점: `Default`

## 주요 기능

- `StartupModule()`과 `ShutdownModule()`을 통한 플러그인 생명주기 확인
- 다른 모듈과 블루프린트에서 사용할 수 있는 `ATemporaryActor` 제공
- 플러그인 콘텐츠를 저장할 수 있는 `Content` 폴더 제공
- `BP_TemporaryActor`를 월드에 배치하여 런타임 동작 검증

## 폴더 구조

```text
Temporary
├─ README.md
├─ Temporary.uplugin
├─ Content
│  └─ BP_TemporaryActor.uasset
└─ Source
   └─ Temporary
      ├─ Temporary.Build.cs
      ├─ Public
      │  ├─ Temporary.h
      │  └─ TemporaryActor.h
      └─ Private
         ├─ Temporary.cpp
         └─ TemporaryActor.cpp
```

### 파일별 역할

- `Temporary.uplugin`: 플러그인의 메타데이터와 포함된 모듈을 정의합니다.
- `Temporary.Build.cs`: `Temporary` 모듈의 빌드 규칙과 엔진 모듈 의존성을 정의합니다.
- `Temporary.h/.cpp`: 플러그인 모듈의 시작과 종료 동작을 구현합니다.
- `TemporaryActor.h/.cpp`: 블루프린트로 확장할 수 있는 Runtime 액터를 구현합니다.
- `BP_TemporaryActor.uasset`: `ATemporaryActor`를 부모로 만든 플러그인 콘텐츠입니다.

## 제작 과정

1. `Plugins/Temporary` 폴더를 생성했습니다.
2. `Temporary.uplugin`에 Runtime 모듈 정보를 작성했습니다.
3. `Source/Temporary` 아래에 `Temporary.Build.cs`를 작성했습니다.
4. `FTemporaryModule`에서 `StartupModule()`과 `ShutdownModule()`을 구현했습니다.
5. 프로젝트의 `.uproject` 파일에 `Temporary` 플러그인을 활성화했습니다.
6. `TEMPORARY_API`가 적용된 `ATemporaryActor`를 `Public` 폴더에 구현했습니다.
7. `ATemporaryActor`를 부모로 하는 `BP_TemporaryActor`를 플러그인 `Content` 폴더에 생성했습니다.
8. 블루프린트를 월드에 배치하고 Play를 실행하여 로그와 화면 메시지를 확인했습니다.

## 모듈 구성

`Temporary.uplugin`은 다음 Runtime 모듈을 포함합니다.

```json
{
  "Name": "Temporary",
  "Type": "Runtime",
  "LoadingPhase": "Default"
}
```

`Temporary.Build.cs`는 다음 엔진 모듈을 사용합니다.

```csharp
PublicDependencyModuleNames.AddRange(
    new string[]
    {
        "Core",
        "CoreUObject",
        "Engine"
    }
);
```

## 설치 및 활성화

1. `Temporary` 폴더 전체를 대상 프로젝트의 `Plugins` 폴더에 복사합니다.
2. 대상 프로젝트의 `.uproject` 파일에 플러그인을 활성화합니다.

```json
{
  "Name": "Temporary",
  "Enabled": true
}
```

3. 프로젝트 파일을 다시 생성합니다.
4. 대상 프로젝트의 Editor Target을 빌드합니다.
5. Unreal Editor를 다시 실행합니다.

`Binaries`와 `Intermediate`는 빌드 과정에서 다시 생성되므로 다른 프로젝트로 이식할 때 제외할 수 있습니다.

## 사용 방법

1. 콘텐츠 브라우저 설정에서 `플러그인 콘텐츠 표시`를 활성화합니다.
2. `Temporary Content`에서 `BP_TemporaryActor`를 찾습니다.
3. `BP_TemporaryActor`를 원하는 맵에 배치합니다.
4. Play를 실행합니다.

정상적으로 실행되면 화면과 Output Log에 다음 메시지가 표시됩니다.

```text
Temporary plugin: ATemporaryActor BeginPlay
```

## 빌드 및 실행 검증

다음 결과를 통해 플러그인의 연결과 실행을 확인했습니다.

- `TemporaryActor.generated.h`와 `TemporaryActor.gen.cpp` 생성
- `TemporaryActor.cpp` 컴파일 성공
- `UnrealEditor-Temporary.dll` 생성
- `/Script/Temporary.ATemporaryActor` 리플렉션 등록 확인
- `BP_TemporaryActor`의 런타임 화면 메시지 출력 확인

## 학습 내용과 문제 해결

### Public과 Private의 차이

다른 모듈이나 블루프린트에서 사용할 헤더는 모듈의 `Public` 폴더에 배치했습니다.

```text
Public/TemporaryActor.h
Private/TemporaryActor.cpp
```

모듈 루트나 `Private` 폴더에 공개 헤더를 배치하면 다른 모듈에서 헤더를 찾지 못할 수 있습니다.

### API 매크로

`ATemporaryActor`에는 다음과 같이 `TEMPORARY_API`를 적용했습니다.

```cpp
class TEMPORARY_API ATemporaryActor : public AActor
```

이 매크로는 `Temporary` DLL의 클래스를 다른 모듈과 블루프린트에서 사용할 수 있도록 내보냅니다.

### IDE의 빨간 줄과 실제 빌드

새 파일을 추가하거나 경로를 변경한 직후 IDE가 include 경로를 다시 인덱싱하기 전까지 빨간 줄이 표시될 수 있습니다. 이 경우 프로젝트 파일을 다시 생성하고 IDE를 재시작합니다. 실제 코드 오류 여부는 Unreal Build Tool의 빌드 결과를 기준으로 확인했습니다.

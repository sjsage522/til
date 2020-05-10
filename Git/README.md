# Git

> --fast-version-control
>
> 🧑 *https://git-scm.com/book/ko/v2*
>
> 👱‍♀️ *https://git-scm.com/book/en/v2*

<hr>

<b>*Contents*</b>

<a href="#시작하기">*1. 시작하기*</a>

<a href="#Git의 기초">*2. Git의 기초*</a>

<hr>

## <a name="시작하기"><b>시작하기</b></a>

### 버전 관리란?

  <b>버전 관리 시스템</b>은 <u>파일 변화를 시간에 따라 기록</u>했다가 나중에 <u>특정 시점의 버전을 다시 꺼내올 수 있는 시스템</u>이다.

<br>

<br>

### Git 기초

<b>*스냅샷*</b>

  Git은 데이터를 파일 시스템 <b>스냅샷의 연속으로 취급</b>하고 크기가 아주 작다.
Git은 커밋하거나 프로젝트의 상태를 저장할 때마다 파일이 존재하는 그 순간을 중요하게 여긴다.

  파일이 달라지지 않았으면 Git은 성능을 위해서 파일을 새로 저장하지 않는다. 단지 이전 상태의 파일에 대한 링크만 저장한다.
Git은 데이터를 <b>스냅샷의 스트림</b>처럼 취급한다.

<br>

<b>*거의 모든 명령을 로컬에서 실행*</b>

  거의 모든 명령이 로컬 파일과 데이터만 사용하기 때문에 네트워크에 있는 다른 컴퓨터는 필요 없다.

  프로젝트의 모든 히스토리가 로컬 디스크에 있기 때문에 모든 명령이 순식간에 실행된다.

<br>

<b>*Git의 무결성*</b>

  Git은 데이터를 저장하기 전에 항상 체크섬을 구하고 그 체크섬으로 데이터를 관리한다. <b>체크섬은 Git에서 사용하는 가장 기본적인(Atomic) 데이터 단위이자 Git의 기본 철학이다.</b>

  Git 없이는 체크섬을 다룰 수 없어서 파일의 상태도 알 수 없고 심지어 데이터를 잃어버릴 수도 있다.

  Git은 SHA-1 해시를 사용하여 체크섬을 만든다. 만든 체크섬은 40자 길이의 16진수 문자열이다.
  파일의 내용이나 디렉토리 구조를 이용하여 체크섬을 구한다.

```bash
24b9da6552252987aa493b52f8696cd6d3b00373
```

  Git은 모든 것을 해시로 식별하기 때문에 이런 값은 여기저기서 보인다. 실제로 Git은 파일을 이름으로 저장하지 않고 <u>해당 파일의 해시로 저장</u>한다.

<br>

<b>*세 가지 상태*</b>

  Git은 파일을 <b>Committed, Modified, Staged</b> 이렇게 세 가지 상태로 관리한다.
이 세 가지 상태는 Git 프로젝트의 세 가지 단계와 연결돼 있다. Git 디렉토리, Staging Area, 워킹 트리 이렇게 세 가지 단계를 이해하고 넘어가자.

<img src="./picture/areas.png">

> <워킹 트리, Staging Area, Git 디렉토리>

  <b>Git 디렉토리</b>는 Git이 프로젝트의 메타데이터와 객체 데이터베이스를 저장하는 곳을 말한다. 

  이 Git 디렉토리가 Git의 핵심이다. 다른 컴퓨터에 있는 저장소를 Clone할 때 Git 디렉토리(.git)가 만들어진다. (또는 git init)

  <b>워킹 트리</b>는 .git에서 프로젝트의 특정 버전을 checkout 한 것이다. Git 디렉토리는 지금 작업하는 디스크에 있고 그 디렉토리 안에 있는 데이터베이스에서 파일을 가져와서 워킹 트리를 만든다.

우리는 이곳에서 프로젝트 작업(개발 및 수정)을 진행한다.

  <b>Staging Area</b>는 Git 디렉토리에 있다. 단순한 파일, 곧 커밋할 파일에 대한 정보를 저장한다. Index라고도 한다.

  Git으로 하는 일은 기본적으로 아래와 같다.

- 워킹 트리에서 파일을 수정한다.
- Staging Area에 파일을 Stage해서 커밋할 스냅샷을 만든다. 모든 파일을 추가할 수도 있고, 선택하여 추가할 수도 있다.
- Staging Area에 있는 파일들을 커밋해서 Git 디렉토리에 영구적인 스냅샷으로 저장한다.

  Git 디렉토리(.git)에 있는 파일들은 Committed 상태이다. 파일을 수정하고 Staging Area에 추가했다면 Staged이다. 

  그리고 Checkout 하고 나서 수정했지만, 아직 Staging Area에 추가하지 않았으면 Modified이다.

<br><br>

### Git 최초 설정

  Git을 설치하고 나면 Git의 사용 환경을 적절하게 설정해 주어야 한다.

  'git config' 명령어로 설정 내용을 확인하고 변경할 수 있다. Git은 이 설정에 따라 동작한다. 

- /etc/gitconfig 파일 : <b>시스템의 모든 사용자와 모든 저장소에 적용되는 설정이다.</b> `git config --system` 옵션으로 이 파일을 읽고 쓸 수 있다. (이 파일은 시스템 전체 설정파일이기 때문에 수정하려면 시스템의 관리자 권한이 필요하다.)
- ~/.gitconfig, ~/.config/git/config 파일 : <b>특정 사용자(즉 현재 사용자)에게만 적용되는 설정이다. </b>`git config --global` 옵션으로 이 파일을 읽고 쓸 수 있다. <u>특정 사용자의 <b>모든</b> 저장소 설정에 적용</u>된다.
- .git/config : 이 파일은 Git 디렉토리에 있고 특정 저장소(혹은 현재 작업중인 프로젝트)에만 적용된다.

  각 설정은 역순으로 우선시 된다.

<br>

<b>*사용자 정보*</b>

  Git을 설치하고 나서 가장 먼저 해야 하는 것은 사용자이름과 이메일 주소를 설정하는 것이다. Git은 커밋할 때마다 이 정보를 사용한다. 
  한 번 커밋한 후에는 정보를 변경할 수 없다.

```bash
$ git config --global user.name "Jun Shin"
$ git config --global user.email junshin@example.com
```

  만약 프로젝트마다 다른 이름과 이메일 주소를 사용하고 싶으면 `--global` 옵션을 빼고 명령을 실행한다.

<br>

<b>*편집기*</b>

  사용자 정보를 설정하고 나면 Git에서 상용할 텍스트 편집기를 고른다. 기본적으로 Git은 시스템의 기본 편집기를 사용한다.

  하지만, vscode 같은 다른 편집기를 사용할 수 있다.

```bash
$ git config --global core.editor "code --wait"
```

<br>

<b>*설정 확인*</b>

  `git config --list` 명령을 실행하면 설정한 모든 것을 보여주어 바로 확인할 수 있다.

  `git config <key>` 명령으로 Git이 특정 key에 대해 어떤 값을 사용하는지 확인할 수 있다.

```bash
$ git config user.name
Jun Shin
```

<br>

<br>

## <a name="Git의 기초">Git의 기초</a>

### Git 저장소 만들기

  주로 다음 두 가지 중 한 가지 방법으로 Git 저장소를 쓰기 시작한다.

- 하직 버전관리를 하지 않는 로컬 디렉토리 하나를 선택해서 Git 저장소를 적용하는 방법
- 다른 어딘가에서 Git 저장소를 <b>Clone</b> 하는 방법

<br>

<b>*기존 디렉토리를 Git 저장소로 만들기*</b>
  버전 관리를 하지 않는 기존 프로젝트를 Git으로 관리하고 싶은 경우 우선 프로젝트의 디렉토리로 이동한다.

  그리고 아래와 같은 명령을 실행한다.

```bash
$ git init
```

  이 명령은 `.git`이라는 하위 디렉토리를 만든다. `.git` 디렉토리에는 저장소에 필요한 뼈대 파일(Skeleton)이 들어 있다. 이 명령만으로는 아직 프로젝트의 어떤 파일도 관리하지 않는다.

  Git이 파일을 관리하게 하려면 저장소에 파일을 추가하고 커밋해야 한다. 
`git add` 명령으로 파일을 추가하고 `git commit` 명령으로 커밋한다. 

```bash
$ git add *.c
$ git add LICENSE
$ git commit -m 'initial project version'
```

<br>

<b>*기존 저장소를 clone 하기*</b>
  다른 프로젝트에 참여하려거나(Contribute) Git 저장소를 복사하고 싶을 때 `git clone` 명령을 사용한다.

  `git clone`을 실행하면 프로젝트 히스토리를 전부 받아온다. 

  `git clone <url>` 명령으로 저장소를 clone한다. `libit2` 라이브러리 소스코드를 Clone 하려면 아래과 같이 실행한다.

```bash
$ git clone https://github.com/libgit2/libgit2
```

  이 명령은 "light2" 라는 디렉토리를 만들고 그 안에 `.git` 디렉토리를 만든다. 그리고 저장소의 데이터를 모두 가져와서 자동으로 가장 최신 버전을 Checkout 해 놓는다.

  `light2` 디렉토리로 이동하면 Checkout으로 생성한 파일을 볼 수 있고 당장 하고자 하는 일을 시작할 수 있다.

<br>

  아래와 같은 명령을 사용하여 저장소를 Clone 하면 light2이 아니라 다른 디렉토리 이름으로 Clone 할 수 있다.

```bash
$ git clone https://github.com/libgit2/libgit2 mylibgit
```

  디렉토리 이름이 `mylight`이라는 것만 빼면 이 명령의 결과와 앞선 명령의 결과는 같다.

<br>

Git은 다양한 프로토콜을 지원한다. 이제까지는 `https://` 프로토콜을 사용했지만 `git://`를 사용할 수도 있고 `user@server:path/to/repo.git`처럼 SSH 프로토콜을 사용할 수도 있다.

<br>

<br>

### 수정하고 저장소에 저장하기

  만질 수 있는 Git 저장소를 하나 만들었고 워킹 디렉토리에 Checkout도 했다. 이제는 파일을 수정하고 파일의 스냅샷을 커밋해 보자.

  파일을 수정하다가 저장하고 싶으면 스냅샷을 커밋한다.

<br>

워킹 디렉토리의 모든 파일은 크게 Tracked(관리 대상)와 Untracked로 나눈다.

  <b>Tracked 파일</b>은 이미 스냅샷에 포함돼 있던 파일이다. Tracked 파일은 또 Unmodified(수정하지 않음)와 Modified 그리고 Staged(커밋으로 저장소에 기록할) 상태 중 하나이다. (간단히, Git이 알고 있는 파일이라는 것이다.)

  그리고 <u>나머지 파일은 모두 Untracked 파일</u>이다. Untracked 파일은 워킹 디렉토리에 있는 파일 중 스냅샷에도 Staging Area에도 포함되지 않은 파일이다.

  처음 저장소를 Clone하면 모든 파일은 Tracked이면서 Unmodified 상태이다. 파일을 Checkout하고 나서 아무것도 수정하지 않았기 때문이다.

  마지막 커밋 이후 아직 아무것도 수정하지 않은 상태에서 어떤 파일을 수정하면 Git은 그 파일을 <b>Modified</b> 상태로 인식한다. 실제로 커밋을 하기 위해서는 이 수정한 파일을 Staged 상태로 만들고, Staged 상태의 파일을 커밋한다. 이런 라이프사이클을 계속 반복한다.

<img src="./picture/lifecycle.png">

<br>

<b>*파일의 상태 확인하기*</b>
  파일의 상태를 확인하려면 보통 `git status`명령을 사용한다. Clone 한 후에 바로 이 명령을 사용하면 아래와 같은 메시지를 볼 수 있다.

```bash
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
nothing to commit, working directory clean
```

  위의 내용은 파일을 하나도 수정하지 않았다는 것을 말해준다. Tracked 파일은 하나도 수정되지 않았다는 의미다.

  Untracked 파일은 아직 없어서 목록에 나타나지 않는다. 그리고 현재 작업 중인 브랜치를 알려주며 서버의 같은 브랜치로부터 진행된 작업이 없는 것을 나타낸다. 기본 브랜치가 master이기 때문에 현재 브랜치 이름이 “master” 로 나온다. 

<br>

  프로젝트에 `README.md` 파일을 만들어보자. `README.md` 파일은 새로 만든 파일이기 때문에 `git status`을 실행하면 'Untracked files'에 들어 있다.

```bash
$ echo 'My Project' > README
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Untracked files:
  (use "git add <file>..." to include in what will be committed)

    README.md

nothing added to commit but untracked files present (use "git add" to track)
```

   `READEME.md` 파일은 "Untracked files" 부분에 속해 있는데 이것은 `READEME.md`파일이 Untracked 상태라는 것을 말한다. Git은 Untracked 파일을 아직 스냅샷(커밋)에 넣어지지 않은 파일이라고 본다.

  파일이 Tracked 상태가 되기 전까지는 Git은 절때 그 파일을 커밋하지 않는다. 그래서 일하면서 바이너리 파일 같은 것을 커밋하는 실수는 하지 않게 된다. `README.md` 파일을 추가해서 직접 Tracked 상태로 만들어 보자.

<br>

<b>*파일을 새로 추적하기*</b>
  `git add` 명령으로 파일을 새로 추적할 수 있다. 아래 명령을 실행하면 Git은 `README.md` 파일을 추적한다.

```bash
$git add README.md
```

  `git status` 명령을 다시 실행하면 `README` 파일이 Tracked 상태이면서 커밋에 추가될 Staged 상태라는 것을 확인할 수 있다.

```bash
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    new file:   README.md
```

  `git add` 명령은 파일 또는 디렉토리의 경로를 아규먼트로 받는다. 디렉토리면 아래에 있는 모든 파일들까지 재귀적으로 추가한다.

<br>

<b>*Modified 상태의 파일을 Stage 하기*</b>
  이미 Tracked 상태인 파일을 수정하는 법을 알아보자. `CONTRIBUTING.md` 라는 파일을 수정하고 나서 `git status` 명령을 다시 실행하면 결과는 아래와 같다.

```bash
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    new file:   README.md

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

    modified:   CONTRIBUTING.md
```

  이 `CONTRIBUTING.md` 파일은 “Changes not staged for commit” 에 있다. 이것은 수정한 파일이 Tracked 상태이지만 아직 Staged 상태는 아니라는 것이다.

  Staged 상태로 만들려면 `git add` 명령을 실행해야 한다.

  `git add` 명령은 파일을 <b>새로 추적할 때도 사용하고 수정한 파일을 Staged 상태로 만들 때도 사용</b>한다. (Merge 할 때 충돌난 상태의 파일을 Resolve 상태로 만들때도 사용한다.)

  add의 의미는 프로젝트에 파일을 추가한다기 보다는 다음 커밋에 추가한다고 받아들이는게 좋다.

  `git add` 명령을 실행하여 `CONTRIBUTING.md` 파일을 Staged 상태로 만들고 `git status` 명령으로 결과를 확인해보자.

```bash
$ git add CONTRIBUTING.md
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    new file:   README.md
    modified:   CONTRIBUTING.md
```

  두 파일 모두 Staged 상태이므로 다음 커밋에 포함된다.
만약 `CONTRIBUTING.md` 파일이 수정되었다고 가정해보자.

```bash
$ vim CONTRIBUTING.md
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    new file:   README.md
    modified:   CONTRIBUTING.md

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

    modified:   CONTRIBUTING.md
```

  `CONTRIBUTING.md` 가 Staged 상태이면서 <b>동시에</b> Unstaged 상태로 나온다.

  `git add` 명령을 실행하면 Git은 파일을 바로 Staged 상태로 만든다. 지금 이 시점에서 커밋을 하면 마지막으로 `git add` 명령을 실행했을 때의 버전이 커밋된다. 

  따라서 `git add` 명령을 실행한 후에 또 파일을 수정하면 `git add` 명령을 다시 실행해서 최신 버전을 Staged 상태로 만들어야 한다.

```bash
$ git add CONTRIBUTING.md
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    new file:   README
    modified:   CONTRIBUTING.md
```

<br>

<b>*파일 상태를 짤막하게 확인하기*</b>
  `git status -s` 또는 `git status --short` 처럼 옵션을 주면 현재 변경한 상태를 짤막하게 보여준다.

```bash
$ git status -s
 M README
MM Rakefile
A  lib/git.rb
M  lib/simplegit.rb
?? LICENSE.txt
```

| 문자 | 설명                                                         |
| ---- | ------------------------------------------------------------ |
| ??   | Git 프로젝트 디렉토리에 새로운 파일이 추가되었으나, Untracked인 파일입니다. |
| A    | 새로운 파일이 추가된 후 git add 명령을 통해 Staged 상태가 된 파일입니다. |
| *M*  | 앞자리는 공백, 뒷자리는 *M* 인 경우 워킹 디렉터리의 파일을 수정(Modified)을 했지만 git add 하지 않은 not Staged 상태를 말합니다. (Modified, not Staged) |
| M    | 워킹 디렉터리에서 파일을 수정하여 Modifed 상태인 파일을 git add로 Staging Area에 등록한 Staged 상태를 말합니다. (Modifed, Staged) |
| M*M* | git add 상태에서 Commit 하지 않고 다시 한 번 수정 후 git add 하지 않은 상태(첫번째 수정 내역은 Staged 상태이지만, 다시 한 번 수정한 내역은 워킹디렉터리에만 존재하고 git add 되지 않은 상태입니다.)<br />이때 Commit을 하게 되면 Staged된 수정 내역만 저장소에 커밋되며, 두 번째 수정내역은 남게되어 *M*상태가 됩니다. |

<br>

<b>*파일 무시하기*</b>
  어떤 파일은 Git이 관리할 필요가 없다. 보통 로그 파일이나 빌드 ㅅ스템이 자동으로 생성한 파일이 그렇다. 그런 파일을 무시하려면 `.gitignore`파일을 만들고 그 안에 무시할 파일 패턴을 적는다. 

  아래는 `.gitignore`파일의 예이다.

```
# 확장자가 .a인 파일 무시
*.a

# 윗 라인에서 확장자가 .a인 파일은 무시하게 했지만 lib.a는 무시하지 않음
!lib.a

# 현재 디렉토리에 있는 TODO파일은 무시하고 subdir/TODO처럼 하위디렉토리에 있는 파일은 무시하지 않음
/TODO

# build/ 디렉토리에 있는 모든 파일은 무시
build/

# doc/notes.txt 파일은 무시하고 doc/server/arch.txt 파일은 무시하지 않음
doc/*.txt

# doc 디렉토리 아래의 모든 .pdf 파일을 무시
doc/**/*.pdf
```



<b>*변경사항 커밋하기*</b>

  Git은 생성하거나 수정하고 나서 `git add` 명령으로 추가하지 않은 파일은 커밋하지 않는다. 그 파일은 여전히 Modified 상태로 남아 있다.

  커밋하기 전에 `git status` 명령으로 모든 것이 Staged 상태인지 확인할 수 있다. 그 후에 `git commit` 을 실행하여 커밋한다.

```bash
$ git commit
```

  메시지를 인라인으로 첨부할 수도 있다. `commit` 명령을 실행할 때 아래와 같이 `-m` 옵션을 사용한다.

```bash
$ git commit -m "Story 182: Fix benchmarks for speed"
[master 463dc4f] Story 182: Fix benchmarks for speed
 2 files changed, 2 insertions(+)
 create mode 100644 README
```

  `commit` 명령은 몇 가지 정보를 출력하는데 위 예제는 (`master`) 브랜치에 커밋했고 체크섬은 (`463dc4f`)이라고 알려준다. 그리고 수정한 파일이 몇 개이고 삭제됐거나 추가된 라인이 몇 라인인지 알려준다.

<br>

<b>*Staging Area 생략하기*</b>
  `git commit` 명령을 실행할 때 `-a` 옵션을 추가하면 Git은 Tracked 상태의 파일을 자동으로 Staging Area에 넣는다. 그래서 `git add` 명령을 실행하는 수고를 덜 수 있다.

```bash
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

    modified:   CONTRIBUTING.md

no changes added to commit (use "git add" and/or "git commit -a")
$ git commit -a -m 'added new benchmarks'
[master 83e38c7] added new benchmarks
 1 file changed, 5 insertions(+), 0 deletions(-)
```

  `-a` 옵션을 사용하면 <b>모든 파일</b>이 자동으로 추가된다. 



<b>*파일 삭제하기*</b>
  Git에서 파일을 제거하려면 `git rm` 명령으로 Tracked 상태의 파일을 삭제한 후에(정확하게는 Staging Area에서 삭제하는 것) 커밋해야 한다. 이 명령은 워킹 디렉토리에 있는 파일도 삭제하기 때문에 실제로 파일도 지워진다.

  Git 명령을 사용하지 않고 단순히 워킹 디렉터리에서 파일을 삭제하고 `git status` 명령으로 상태를 확인하면 Git은 현재 “Changes not staged for commit” (즉, *Unstaged* 상태)라고 표시해준다.

```bash
$ rm PROJECTS.md
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        deleted:    PROJECTS.md

no changes added to commit (use "git add" and/or "git commit -a")
```

  그리고 `git rm` 명령을 실행하면 삭제한 파일은 Staged 상태가 된다.

```bash
$ git rm PROJECTS.md
rm 'PROJECTS.md'
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    deleted:    PROJECTS.md
```

  커밋하면 파일은 삭제되고 Git은 이 파일을 더는 추적하지 않는다. 이미 파일을 수정했거나 Staging Area에 추가했다면 `-f` 옵션을 주어 강제로 삭제해야 한다.

<br>

<b>*파일 이름 변경하기*</b>
  Git은 파일 이름의 변경이나 파일의 이동을 명시적으로 관리하지 않는다.
다시 말해서 파일 이름이 변경됐다는 별도의 정보를 저장하지 않는다.

  아래와 같이 파일 이름을 변경할 수 있다.

```bash
$ git mv file_from file_to
```

  이 명령을 실행하고 Git의 상태를 확인해보면 Git은 이름이 바뀐 사실을 알고 있다.

```bash
$ git mv README.md README
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    renamed:    README.md -> README
```

  사실 `git mv` 명령은 아래 명령어를 수행한 것과 완전 똑같다.

```bash
$ mv README.md README
$ git rm README.md
$ git add README
```

<br>

> Git 저장소에서만 삭제하고 실제 파일은 남겨두고 싶은 경우
> --cached 옵션을 사용하여 삭제
>
> $ git rm --cached testFile


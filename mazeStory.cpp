#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES	1

#include <stdio.h>
#include <bangtal.h>
#include <stdlib.h>
#include <time.h>
#include<string>
#include<string.h>

//공통 오브젝트
ObjectID prince, princess, enemy, inventory, invenWin, invenB_U, invenB_C, black_win;
int lineNUM = 0;

bool invenOpen = false; //인벤토리


// 인트로
SceneID scene1, scene2;
ObjectID line, line2; //대사
ObjectID KingE, KingW, Owner; //캐릭터들
TimerID timer1; //씬2 진입 타이머

bool lineS1 = false; 
bool lineS2 = false; //대사 변수
const char* ScriptS1[4] = {"line/슬라이드3.png","line/슬라이드4.png" ,"line/슬라이드5.png" ,"line/슬라이드6.png" }; //씬1 대사

const char* ScriptS2[11] = { "line/슬라이드7.png" ,"line/슬라이드8.png","line/슬라이드9.png","line/슬라이드10.png","line/슬라이드11.png","line/슬라이드12.png","line/슬라이드13.png",
						"line/슬라이드14.png" , "line/슬라이드15.png" , "line/슬라이드16.png" ,"line/슬라이드17.png"}; //씬2 대사


//스테이지 1 _ 공주와 문에서 갈라짐.
SceneID scene3;
ObjectID line3; //대사
TimerID timer2, timer3, timer4; //씬3 진입 타이머 / 공주 타이머 / 문 타이머

bool lineS3 = false;
const char* ScriptS3[7] = { "line/슬라이드18.png" ,"line/슬라이드19.png","line/슬라이드20.png","line/슬라이드21.png","line/슬라이드22.png","line/슬라이드23.png","line/슬라이드24.png" };


//스테이지 2 _ 칠득 대면
SceneID scene4;
ObjectID line4; //대사
int Ex = 1280; int Edirct = 1000; int dxE = 10; int imageNumE = 0; //칠득이 x좌표 저장용 / 칠득이 목적지 / 칠득이 속도 / 프레임 돌리기용
Second Espeed = 0.05f; //칠득이 타이머

TimerID BossTimer; //보스전 시간 / 걷는 시간(프레임 타임) / 
TimerID enemyWalk; TimerID timer5;

bool lineS4 = false; //대사
const char* ScriptS4[7] = { "line/슬라이드25.png" ,"line/슬라이드26.png","line/슬라이드27.png","line/슬라이드28.png","line/슬라이드29.png","line/슬라이드30.png","line/슬라이드31.png" };

bool battle = false; //싸움 시작하면 true.
bool walkingE_come = false; //칠득이 걷기_다가오기
bool walkingE_away = false; //칠득이 도망치기

const char* imageE[3] = { "image/C1.png","image/C2.png" ,"image/C3.png" }; //칠득 기본
const char* imageE_R[3] = {"image/CR_1.png","image/CR_2.png" ,"image/CR_3.png" }; //칠득 기본 오른쪽
const char* imageE_D[2] = { "image/CD_1.png","image/CD_2.png" }; //칠득 데미지
const char* imageE_DR[2] = { "image/CDR_1.png" ,"image/CDR_2.png" }; //칠득 데미지 오른쪽
const char* imageE_F[3] = { "image/CF_1.png","image/CF_2.png", "image/CF_3.png" }; //칠득 공격
const char* imageE_FR[3] = { "image/CFR_1.png","image/CFR_2.png", "image/CFR_3.png" }; //칠득 공격 오른쪽


//스테이지 3 _ 보스전
SceneID scene5;
TimerID setTarget; //왕자 목표물지정하는 타이머_ 몇초마다 왕자의 현재위치를 목표로 지정하는 타이머
TimerID HitEnemyt, HitPrincet; //각각 칠득, 왕자 공격할때 쓸 타이머
TimerID DEnemyt, DPrincet; //각각 데미지 입었을 때 쓸 타이머

int NumPrinceF = 0;
int TargetX; //목표 좌표 저장하는 변수
int enemyStartX; //칠득이 출발좌표 저장.
bool HitPrince = false; bool HitEnemy = false; //왕자 공격할때, 칠득 공격할때.
bool EnemyL = true; //칠득이가 왼쪽인지, 오른쪽인지...

ObjectID HP[3]; ObjectID HE[4]; //왕자, 칠득 체력

const char* imageP_F[3] = { "image/PFL_1.png","image/PFL_2.png", "image/PFL_3.png" }; //왕자 공격
const char* imageP_FR[3] = { "image/PF_1.png","image/PF_2.png", "image/PF_3.png" }; //왕자 공격 오른쪽

bool HP1[3] = { true, true, true };
bool HE1[4] = { true, true, true, true }; //하트 터지는거 판정하는거

//타겟 좌표에 도착하면 칠득이 공격모션 재생. 어떤 일정 범위 내에 있으면 피격판정.
//목숨 3개씩? 하기. 위에 대결하는 UI 만들기.... 하..... ^^ 

// 칠득이 모션 바꾸는거 해야함.


//스테이지 4_칠득이 도망친 이후
SceneID scene6;
TimerID timer6;

ObjectID line6; //대사

bool lineS6 = false;
const char* ScriptS6[4] = { "line/슬라이드32.png" ,"line/슬라이드33.png","line/슬라이드34.png","line/슬라이드35.png" };


//스테이지 5_간단한 열쇠찾기
SceneID scene7;
TimerID timer7;
bool close7 = true; 
bool doorSee = false; //문 조사후 열쇠 가능
bool Key7 = false; //문 조사후 열쇠 가능

ObjectID line7; //대사

bool lineS7 = false;
const char* ScriptS7[4] = { "line/슬라이드36.png" ,"line/슬라이드37.png","line/슬라이드38.png","line/슬라이드39.png" };


//스테이지 5_공주와의 대화 1
SceneID scene8;
TimerID timer8, timer9; //공주 타이머 / 씬 타이머

ObjectID line8; //대사

bool lineS8 = false;
const char* ScriptS8[12] = { "line/슬라이드40.png" ,"line/슬라이드41.png","line/슬라이드42.png","line/슬라이드43.png",
"line/슬라이드44.png" ,"line/슬라이드45.png","line/슬라이드46.png","line/슬라이드47.png" ,
"line/슬라이드48.png" ,"line/슬라이드49.png","line/슬라이드50.png","line/슬라이드51.png" };


//스테이지 6_퍼즐게임
SceneID scene9;
TimerID timer10; //씬 타이머


//스테이지 7_공주 구출
SceneID scene10; //공주 잡힌곳으로 이동

ObjectID line10; //대사

bool lineS10 = false;
const char* ScriptS10[3] = {"line/슬라이드52.png", "line/슬라이드53.png", "line/슬라이드54.png" };


//스테이지 8_ 재대결
SceneID scene11; //싸움터 2
TimerID timer12, timer13;

ObjectID HP0[3]; ObjectID HE0[10]; //왕자, 칠득 체력

bool HP11[3] = { true, true, true };
bool HE11[10] = { true, true, true, true, true, true, true, true, true, true }; //하트 터지는거 판정하는거


//스테이지 9_ 엔딩 전
SceneID scene12;
TimerID timer14, timer15;

ObjectID line12; //대사

bool lineS12 = false;

const char* Script12[38] = { "line/슬라이드55.png", "line/슬라이드56.png", "line/슬라이드57.png" ,"line/슬라이드58.png", "line/슬라이드59.png", "line/슬라이드60.png" ,
							"line/슬라이드61.png", "line/슬라이드62.png", "line/슬라이드63.png" ,"line/슬라이드64.png", "line/슬라이드65.png", "line/슬라이드66.png" , 
							"line/슬라이드67.png", "line/슬라이드68.png", "line/슬라이드69.png" ,"line/슬라이드70.png", "line/슬라이드71.png", "line/슬라이드72.png" ,
							"line/슬라이드73.png", "line/슬라이드74.png", "line/슬라이드75.png" ,"line/슬라이드76.png", "line/슬라이드77.png", "line/슬라이드78.png" ,
							"line/슬라이드79.png", "line/슬라이드80.png", "line/슬라이드81.png" ,"line/슬라이드82.png", "line/슬라이드83.png", "line/슬라이드84.png" ,
							"line/슬라이드85.png", "line/슬라이드86.png", "line/슬라이드87.png" ,"line/슬라이드88.png", "line/슬라이드89.png", "line/슬라이드90.png" ,
							"line/슬라이드91.png", "line/슬라이드92.png"}; //대사모음


//스테이지 10_ 엔딩
SceneID scene13;
TimerID timer16;

ObjectID line13; //대사
const char* Script13[8] = { "line/슬라이드93.png", "line/슬라이드94.png", "line/슬라이드95.png" ,"line/슬라이드96.png", "line/슬라이드97.png", "line/슬라이드98.png" ,
							"line/슬라이드99.png", "line/슬라이드100.png"}; //대사모음


//스테이지 11_엔딩
SceneID scene14;
TimerID timer17;

ObjectID line14; //대사
const char* Script14[36] = { "line/슬라이드101.png" ,"line/슬라이드102.png", "line/슬라이드103.png", "line/슬라이드104.png" ,
							"line/슬라이드105.png", "line/슬라이드106.png", "line/슬라이드107.png" ,"line/슬라이드108.png", "line/슬라이드109.png", "line/슬라이드110.png" ,
							"line/슬라이드111.png", "line/슬라이드112.png", "line/슬라이드113.png" ,"line/슬라이드114.png", "line/슬라이드115.png", "line/슬라이드116.png" ,
							"line/슬라이드117.png", "line/슬라이드118.png", "line/슬라이드119.png" ,"line/슬라이드120.png", "line/슬라이드121.png", "line/슬라이드122.png" ,
							"line/슬라이드123.png", "line/슬라이드124.png", "line/슬라이드125.png" ,"line/슬라이드126.png", "line/슬라이드127.png", "line/슬라이드128.png" ,
							"line/슬라이드129.png", "line/슬라이드130.png", "line/슬라이드131.png" ,"line/슬라이드132.png", "line/슬라이드133.png", "line/슬라이드134.png"
							"line/슬라이드135.png", "line/슬라이드136.png", "line/슬라이드137.png" }; //대사모음





//인벤토리 

ObjectID invenItem[10];
bool ItemExist[10] = { false, };


//캐릭터 움직이기 변수

SceneID SceneNow = scene2; //왕자 있을 씬, 초깃값은 씬 2
int x = 100, y = 67; //왕자 초기 좌표
int dx = 0, dy = 0; //변화 좌표
const char* imageP_R[9] = { "image/P1.png" , "image/P2.png" , "image/P3.png" , "image/P4.png" , "image/P5.png" , "image/P6.png" , "image/P7.png" , "image/P8.png", "image/P9.png" };
const char* imageP_L[9] = { "image/L_P1.png" , "image/L_P2.png" , "image/L_P3.png" , "image/L_P4.png" , "image/L_P5.png" , "image/L_P6.png" , "image/L_P7.png" , "image/L_P8.png", "image/L_P9.png" };
int imageNUM_L = 0; int imageNumSet_L = 0; int imageNUM_R = 0; int imageNumSet_R = 0;
bool Walking_L = false; bool Walking_R = false;
bool CanWalk = true;

#define ANIMATION_TIME		0.05f //프레임 시간
#define ANIMATION_STEP		12 //이동 픽셀 수

TimerID timerp = createTimer(ANIMATION_TIME); //이동 타이머

//--------------------- 퍼즐게임 -----------------------

//새로 넣은 부분
using namespace std;
SceneID scenegame;
ObjectID startbutton, restart, endbutton;
time_t time_start, time_end;
int time_d;
string time_s;
const char* time_f;

struct POS {
	int x, y;
};
const POS positions[16] = {
	{300, 470}, {450, 470}, {600, 470}, {750, 470},
	{300, 320}, {450, 320}, {600, 320}, {750, 320},
	{300, 170}, {450, 170}, {600, 170}, {750, 170},
	{300, 20}, {450, 20}, {600, 20}, {750, 20},
};

ObjectID initObjects[16];
ObjectID gameObjects[16];
int blank = 15;

TimerID timerMixing;
const int mixCount = 100;
const Second animationTime = 0.05f;
int mixing = 0;

bool game = false;

void game_init()
{
	scenegame = createScene("KOBE", "image/scene7.png");

	char image[20];
	for (int i = 0; i < 16; i++) {
		sprintf_s(image, "image/%d.png", i + 1);
		initObjects[i] = createObject(image);
		gameObjects[i] = initObjects[i];

		locateObject(gameObjects[i], scenegame, positions[i].x, positions[i].y);
		showObject(gameObjects[i]);
	}

	startbutton = createObject("image/start.png");
	locateObject(startbutton, scenegame, 540, 50);
	scaleObject(startbutton, 2);
	showObject(startbutton);

	endbutton = createObject("image/end.png");
	locateObject(endbutton, scenegame, 595, 10);
	scaleObject(endbutton, 1);

	blank = 15;
	game = false;

	srand((unsigned int)time(NULL));
	timerMixing = createTimer();
}
// 게임인덱스, 게임 무브? gameObjects[i] -> 랜덤 게임오브젝트 골라서?
int game_index(ObjectID oid) {
	for (int i = 0; i < 16; i++) {
		if (gameObjects[i] == oid) return i;
	}

	return -1;
}

bool game_move(int index)
{
	if (index < 0) return false;
	if (index > 15) return false;

	if (index == (blank - 4) || index == (blank + 4) ||
		(index == (blank - 1) && (blank % 4) != 0) ||
		(index == (blank + 1) && (blank % 4) != 3)) {

		locateObject(gameObjects[index], scenegame, positions[blank].x, positions[blank].y);
		locateObject(gameObjects[blank], scenegame, positions[index].x, positions[index].y);

		ObjectID o = gameObjects[blank];
		gameObjects[blank] = gameObjects[index];
		gameObjects[index] = o;

		blank = index;

		return true;
	}

	return false;
}
//게임 랜덤 무브 함수 -> 사용자 정의 함수 
void game_random_move()
{
	bool possible = false;
	int next = -1;
	while (!possible) {
		switch (rand() % 4) {
		case 0:		// UP
			next = blank - 4;
			break;
		case 1:		// DOWN
			next = blank + 4;
			break;
		case 2:		// LEFT
			next = (blank % 4 != 0) ? (blank - 1) : -1;
			break;
		case 3:		// RIGHT
			next = (blank % 4 != 3) ? (blank + 1) : -1;
			break;
		}

		possible = game_move(next);
	}
}

void game_prepare()
{
	hideObject(gameObjects[blank]);

	mixing = mixCount;

	// start to mix
	setTimer(timerMixing, animationTime);
	startTimer(timerMixing);
}

bool game_check()
{
	for (int i = 0; i < 16; i++) {
		if (gameObjects[i] != initObjects[i]) return false;
	}

	return true;
}

void game_end()
{
	game = false;

	showObject(gameObjects[blank]);
	showObject(endbutton);
}


// -------------------------------------------------------


//오브젝트 생성
ObjectID CreateObject1(const char* Obimage, SceneID Scene, int x, int y) {
	ObjectID object = createObject(Obimage);
	locateObject(object, Scene, x, y);
	return object;
}


//공통 오브젝트 만드는 함수_ 왕자, 인벤토리 셋팅.
void SetBaseObj(SceneID scene = SceneNow) {
	
	prince = CreateObject1("image/P1.png", scene, x, y);
	inventory = CreateObject1("image/inven.png", scene, 1180, 570);
	invenWin = CreateObject1("image/Inven_win.png", scene, 120, 30);
	invenB_U = CreateObject1("image/Inven_close.png", scene, 330, 140);
	invenB_C = CreateObject1("image/Inven_use.png", scene, 809, 140);

	for (int i = 0; i < 10; i++) { //인벤토리 생성

		if (i < 5) {
			invenItem[i] = CreateObject1("image/Inven_itemBlank.png", scene, 269 + (148 * i), 370);

		}
		else {
			invenItem[i] = CreateObject1("image/Inven_itemBlank.png", scene, 269 + (148 * (i - 5)), 237);

		}
	}

	showObject(prince); showObject(inventory);

	startTimer(timerp); //왕자 걷도록 해주는 타이머

}


//키보드콜백 함수 _ 키 설정
void keyboardCallback(KeyCode code, KeyState state)
{
	if (code == KeyCode::KEY_D) {		// RIGHT

		if (state == KeyState::KEY_PRESSED) {
			dx += ANIMATION_STEP;
			Walking_R = true;
		}
		else { //뗐을때
			dx -= ANIMATION_STEP;
			setObjectImage(prince, imageP_R[0]);
			Walking_R = false;
			imageNUM_R = 0;
		}
	}
	else if (code == KeyCode::KEY_A) {		// LEFT
		if (state == KeyState::KEY_PRESSED) {
			dx -= ANIMATION_STEP;
			Walking_L = true;

		}
		else {
			dx += ANIMATION_STEP;
			setObjectImage(prince, imageP_L[0]);
			Walking_L = false;
			imageNUM_L = 0;
		}
	}
	else if (code == KeyCode::KEY_SPACE) { //조사하는 키
		if (SceneNow == scene3) { //씬 3에서...
			if (x > 265 && x < 450) { //문에 있을 때 하면...

				setSceneImage(scene3, "image/scene0.jpg");
				hideObject(prince); hideObject(inventory); //오브제 숨기기

				SceneNow = scene4; //씬 4를 현재 씬으로 설정
				timer4 = createTimer(2.0f);
				startTimer(timer4); //타이머 시작
			}
		}
		else if (SceneNow == scene5 || SceneNow == scene11) { //보스전에서...스페이스바
			if (state == KeyState::KEY_PRESSED) {
				HitPrince = true;
			}
			else {
				HitPrince = false;
			}
		}
		else if (SceneNow == scene6) {
			if (x > 950 && x < 1080) { //문에 있을 때 하면...

				setSceneImage(scene6, "image/scene0.jpg");
				hideObject(prince); hideObject(inventory); //오브제 숨기기

				SceneNow = scene7; //씬 4를 현재 씬으로 설정
				timer6 = createTimer(2.0f);
				startTimer(timer6); //타이머 시작
			}
		}
		else if (SceneNow == scene7) {
			if (state == KeyState::KEY_PRESSED) {
				if (x > 755 && x < 900) { //문에 있을 때 하면...
					if (close7 && !doorSee) { //닫힌상태+문 안본상태
						setObjectImage(line7, ScriptS7[2]);
						doorSee = true;
					}
					else if (!close7) {
						lineS7 = false;
						lineNUM = 0; //넘버 초기화

						SceneNow = scene8;
						lineS8 = true;
						hideObject(prince), hideObject(inventory);
						timer8 = createTimer(2.0f);
						startTimer(timer8);
						setSceneImage(scene7, "image/scene0.jpg");

					}

				}if (doorSee && (x > 96 && x < 175)) {//해골조사
					Key7 = true; //열쇠얻음
					setObjectImage(line7, ScriptS7[3]);
					setObjectImage(invenItem[0], "image/Inven_item1.png"); //열쇠
				}
			}
			
		}
		else if (SceneNow == scene8) {
			if ((x > 200 && x < 400) && !lineS8) { //문에 있을 때 + 대사 끝났을때 들어가기...

				CanWalk = false;

				setSceneImage(scene8, "image/scene0.jpg");
				hideObject(prince); hideObject(inventory); //오브제 숨기기

				SceneNow = scene9; //씬 4를 현재 씬으로 설정
				timer10 = createTimer(2.0f);
				startTimer(timer10); //타이머 시작
			}
		}
		else if (SceneNow == scene9) {
			if (x > 500 && x < 700) { //퍼즐게임 시작하는 조건

				CanWalk = false;

				//퍼즐 게임 시작
				game_init();
				enterScene(scenegame);
			}
		}
	}
}


//보스전 전용 함수 ---------------------------------------------

//칠득이 등장시키고 + 움직이는 함수
void enemySet() {
	walkingE_come = true; //걷기 시작

	enemy = CreateObject1(imageE[0], scene4, Ex, 70); //적 생성
	showObject(enemy);

	enemyWalk = createTimer(Espeed);
	startTimer(enemyWalk); //걷기 타이머 즉시 실행
}

void enemyRestart() { //다시 걷게 시키는함수
	walkingE_come = true;
	Edirct = 600;
	dxE = 13;
	Espeed = 0.02f;

	setTimer(enemyWalk, Espeed);
	startTimer(enemyWalk);
}

void enemyBattle() { //보스전 전용함수
	
	battle = true; //보스전 활성화
	CanWalk = true; //왕자 걷기 활성화
	HP1[0] = true; HP1[1] = true; HP1[2] = true;

	Ex = 1000; //초기 x좌표 1000
	enemyStartX = 1000; //초기좌표 저장해두기.
	dxE = 10; //10픽셀씩 움직이는 칠득
	TargetX = x; //맨 처음 타겟좌표는 초기 왕자좌표
	Edirct = TargetX; //초기 칠득이 목표점.
	locateObject(enemy, SceneNow, Ex, 70); //칠득이 x좌표 Ex로 배치

	setTarget = createTimer(0.05f); //0.05초에 1번 왕자 좌표로 목표를 지정할것임.
	enemyWalk = createTimer(0.03f); //칠득이 걷기 속도 0.03으로 지정
	HitEnemyt = createTimer(0.5f); HitPrincet = createTimer(0.5f);//0.7초간 공격모션 재생

	if (SceneNow == scene5) {
		for (int i = 0; i < 4; i++) { //체력 생성
			if (i < 3) {
				HP[i] = CreateObject1("image/H.png", scene5, 195 + (52 * i), 572); //왕자 하트
				showObject(HP[i]); //하트 보이기
			}
			HE[i] = CreateObject1("image/H.png", scene5, 900 + (52 * i), 572); //칠득 하트
			showObject(HE[i]); //하트 보이기
		}
	}else if (SceneNow == scene11) {
		for (int i = 0; i < 10; i++) { //체력 생성
			if (i < 3) {
				HP0[i] = CreateObject1("image/H.png", scene11, 195 + (52 * i), 572); //왕자 하트
				showObject(HP0[i]); //하트 보이기
			}
			if (i < 5) {
				HE0[i] = CreateObject1("image/H.png", scene11, 900 + (52 * i), 572); //칠득 하트
			}
			else HE0[i] = CreateObject1("image/H.png", scene11, 900 + (52 * (i-5)), 492); //칠득 하트
			showObject(HE0[i]); //하트 보이기
		}
	}

	startTimer(setTarget); startTimer(enemyWalk); //타이머 돌리기 시작

}

void isitHit_E11() { //칠득 피격 판정2
	HitPrincet = createTimer(0.3f);
	startTimer(HitPrince);
	stopTimer(timerp); //왕자 잠시 멈춤

	if ((x + 50 < Ex && x + 100 > Ex) && EnemyL) { //칠득이 왼쪽볼때

		setObjectImage(enemy, "image/CD_1.png"); //왼쪽보고 맞음.

		for (int i = 0; i < 10; i++) {
			if (HE11[i]) {
				if (i == 9) {
					hideObject(HE0[i]); //끝에 있는 거부터 깎기

					hideObject(HE[3]); //끝에 있는 거부터 깎기

					Ex = 800; x = 100;
					SceneNow = scene12;
					stopTimer(enemyWalk);
					CanWalk = false;
					battle = false;

					SetBaseObj(); //설정해줌.

					timer13 = createTimer(2.0f);
					startTimer(timer13);
					setSceneImage(scene11, "image/scene0.jpg");
					hideObject(enemy); hideObject(prince);

				}
				
				HE11[i] = false;
				hideObject(HE0[i]); //끝에 있는 거부터 깎기.
				break;
			}
		}
		

	}
	else if ((x < Ex + 180 && x > Ex + 50) && !EnemyL) { //칠득이 오른쪽볼때

		setObjectImage(enemy, "image/CDR_1.png"); //오른쪽보고 맞음

		for (int i = 0; i < 10; i++) {
			if (HE11[i]) {
				if (i == 9) {
					hideObject(HE0[3]); //끝에 있는 거부터 깎기

					Ex = 800; x = 100;
					SceneNow = scene12;
					stopTimer(enemyWalk);
					CanWalk = false;
					battle = false;

					SetBaseObj(); //설정해줌.

					timer13 = createTimer(2.0f);
					startTimer(timer13);
					setSceneImage(scene11, "image/scene0.jpg");
					hideObject(enemy); hideObject(prince);
				}

				HE11[i] = false;
				hideObject(HE0[i]); //끝에 있는 거부터 깎기.
				break;
			}
		}

	}

}

void isitHit_E() { //칠득 피격 판정
	HitPrincet = createTimer(0.3f);
	startTimer(HitPrince);
	stopTimer(timerp); //왕자 잠시 멈춤
	
	if ((x + 50 < Ex && x + 100 > Ex) && EnemyL) { //칠득이 왼쪽볼때
		
		setObjectImage(enemy, "image/CD_1.png"); //왼쪽보고 맞음.
		
		if (HE1[0]) { //3개 다 있는경우
			HE1[0] = false; //체력 깎아버리기
			hideObject(HE[0]); //끝에 있는 거부터 깎기.
		}
		else if (HE1[1]) { //
			HE1[1] = false; //체력 깎아버리기
			hideObject(HE[1]); //끝에 있는 거부터 깎기.
		}
		else if (HE1[2]) {
			HE1[2] = false; //체력 깎아버리기
			hideObject(HE[2]); //끝에 있는 거부터 깎기
		}
		else if (HE1[3]) { //이러면 이제 다음 넘어감.
			hideObject(HE[3]); //끝에 있는 거부터 깎기

			Ex = 800; x = 100;
			SceneNow = scene6;
			stopTimer(enemyWalk);
			CanWalk = false;
			battle = false;

			enemy = CreateObject1(imageE[0], scene6, Ex, 70);
			line6 = CreateObject1(ScriptS6[0], scene6, 120, 455); //대사
			lineS6 = true;
			showObject(enemy); showObject(line6);
			SetBaseObj(); //설정해줌.

			enterScene(scene6);
		}

	}
	else if ((x < Ex + 180 && x > Ex + 50) && !EnemyL) { //칠득이 오른쪽볼때

		setObjectImage(enemy, "image/CDR_1.png"); //오른쪽보고 맞음
		
		if (HE1[0]) { //3개 다 있는경우
			HE1[0] = false; //체력 깎아버리기
			hideObject(HE[0]); //끝에 있는 거부터 깎기.
		}
		else if (HE1[1]) { //
			HE1[1] = false; //체력 깎아버리기
			hideObject(HE[1]); //끝에 있는 거부터 깎기.
		}
		else if (HE1[2]) {
			HE1[2] = false; //체력 깎아버리기
			hideObject(HE[2]); //끝에 있는 거부터 깎기
		}
		else if (HE1[3]) { //이러면 이제 다음 넘어감.
			hideObject(HE[3]); //끝에 있는 거부터 깎기

			Ex = 800; x = 100;
			SceneNow = scene6;
			stopTimer(enemyWalk);
			CanWalk = false;
			battle = false;

			enemy = CreateObject1(imageE[0], scene6, Ex, 70);
			line6 = CreateObject1(ScriptS6[0], scene6, 120, 455); //대사
			lineS6 = true;
			showObject(enemy); showObject(line6);
			SetBaseObj(); //설정해줌.

			enterScene(scene6);
		}

	}

}

void IsitHit_P11() { //왕자 피격 판정

	if ((x < Ex && x + 80 > Ex) && EnemyL) { //칠득이가 왼쪽으로 HIT하고있는 도중에 들어오면....

		stopTimer(enemyWalk); //패는 타이머 정지

		if (HP11[0]) { //3개 다 있는경우
			HP11[0] = false; //체력 깎아버리기
			hideObject(HP0[2]); //끝에 있는 거부터 깎기.
		}
		else if (HP11[1]) { //
			HP11[1] = false; //체력 깎아버리기
			hideObject(HP0[1]); //끝에 있는 거부터 깎기.
		}
		else if (HP11[2]) {
			HP11[2] = false; //체력 깎아버리기
			hideObject(HP0[0]); //끝에 있는 거부터 깎기
		}

		DPrincet = createTimer(0.1f); //0.1초간 재생

		if (EnemyL) { //왼쪽으로 걸음
			setObjectImage(prince, "image/R_D1.png"); //왼쪽보고 맞음.
		}
		else {
			setObjectImage(prince, "image/L_D1.png");
		}

		startTimer(DPrincet);
	}
	else if ((x < Ex + 150 && x > Ex + 50) && !EnemyL) { //칠득이 오른쪽보고 때렸을때.
		stopTimer(enemyWalk); //패는 타이머 정지

		if (HP11[0]) { //3개 다 있는경우
			HP11[0] = false; //체력 깎아버리기
			hideObject(HP0[2]); //끝에 있는 거부터 깎기.
		}
		else if (HP11[1]) { //
			HP11[1] = false; //체력 깎아버리기
			hideObject(HP0[1]); //끝에 있는 거부터 깎기.
		}
		else if (HP11[2]) {
			HP11[2] = false; //체력 깎아버리기
			hideObject(HP0[0]); //끝에 있는 거부터 깎기
		}

		DPrincet = createTimer(0.1f); //0.1초간 재생

		if (EnemyL) { //왼쪽으로 걸음
			setObjectImage(prince, "image/R_D1.png"); //왼쪽보고 맞음.
		}
		else {
			setObjectImage(prince, "image/L_D1.png");
		}

		startTimer(DPrincet);
	}

}



void IsitHit_P() { //왕자 피격 판정

	if ((x < Ex && x + 80 > Ex) && EnemyL) { //칠득이가 왼쪽으로 HIT하고있는 도중에 들어오면....
		
		stopTimer(enemyWalk); //패는 타이머 정지
		
		if (HP1[0]) { //3개 다 있는경우
			HP1[0] = false; //체력 깎아버리기
			hideObject(HP[2]); //끝에 있는 거부터 깎기.
		}
		else if (HP1[1]) { //
			HP1[1] = false; //체력 깎아버리기
			hideObject(HP[1]); //끝에 있는 거부터 깎기.
		}
		else if (HP1[2]){
			HP1[2] = false; //체력 깎아버리기
			hideObject(HP[0]); //끝에 있는 거부터 깎기
		}

		DPrincet = createTimer(0.1f); //0.1초간 재생

		if (EnemyL) { //왼쪽으로 걸음
			setObjectImage(prince, "image/R_D1.png"); //왼쪽보고 맞음.
		}
		else {
			setObjectImage(prince, "image/L_D1.png");
		}

		startTimer(DPrincet);
	}
	else if ((x < Ex + 150 && x > Ex + 50) && !EnemyL) { //칠득이 오른쪽보고 때렸을때.
		stopTimer(enemyWalk); //패는 타이머 정지

		if (HP1[0]) { //3개 다 있는경우
			HP1[0] = false; //체력 깎아버리기
			hideObject(HP[2]); //끝에 있는 거부터 깎기.
		}
		else if (HP1[1]) { //
			HP1[1] = false; //체력 깎아버리기
			hideObject(HP[1]); //끝에 있는 거부터 깎기.
		}
		else if (HP1[2]) {
			HP1[2] = false; //체력 깎아버리기
			hideObject(HP[0]); //끝에 있는 거부터 깎기
		}

		DPrincet = createTimer(0.1f); //0.1초간 재생

		if (EnemyL) { //왼쪽으로 걸음
			setObjectImage(prince, "image/R_D1.png"); //왼쪽보고 맞음.
		}
		else {
			setObjectImage(prince, "image/L_D1.png");
		}

		startTimer(DPrincet);
	}

}



//-------------------------------------------------------------------- 진행 함수 모음집 끝


//타이머콜백 함수
void timerCallback(TimerID timer)
{
	//왕자 걷는 타이머
	if (timer == timerp) {

		if (CanWalk) {
			if (x < 0 || x > 1180) {
				if (x < 0) x = 0;
				if (x > 1180) x = 1180; //이 이상으로 못 빠져나감.
			}
			if (SceneNow == scene8 && x > 400) x = 400; //씬 8에서만 x에제한...
			x += dx; y += dy;
			locateObject(prince, SceneNow, x, y);

			if (Walking_R) {
				imageNumSet_R = (imageNUM_R % 8) + 1;
				setObjectImage(prince, imageP_R[imageNumSet_R]);
				imageNUM_R++;
			}

			if (Walking_L) {
				imageNumSet_L = (imageNUM_L % 8) + 1;
				setObjectImage(prince, imageP_L[imageNumSet_L]);
				imageNUM_L++;
			}
		}
		if (HitPrince && SceneNow == scene5 || HitPrince && SceneNow == scene11) { //보스전에서 공격모션 재생
			
			NumPrinceF++;
			int imageEN3 = (NumPrinceF % 3); 
			if (Walking_L) setObjectImage(prince, imageP_F[imageEN3]);
			else if (Walking_R) setObjectImage(prince, imageP_FR[imageEN3]);
			else if (x > Ex)  setObjectImage(prince, imageP_F[imageEN3]);
			else setObjectImage(prince, imageP_FR[imageEN3]);

			if (SceneNow == scene5)isitHit_E();
			if (SceneNow == scene11) isitHit_E11();
		}

		setTimer(timerp, ANIMATION_TIME);
		startTimer(timerp);
	}

	if (timer == timer1) {
		enterScene(scene2); //씬2 진입
		stopTimer(timer1);
	}

	if (timer == timer2) {
		enterScene(scene3); //씬3 진입

		princess = CreateObject1("image/Ps1_L.png", scene3, 800, 70);
		prince = CreateObject1(imageP_R[0], scene3, 350, 70);
		showObject(prince), showObject(princess);
		stopTimer(timer2);
	}

	if (timer == timer3) { //공주연출
		setObjectImage(line3, ScriptS3[lineNUM]); //대사창 복구
		lineS3 = true;
		stopTimer(timer3);
	}

	if (timer == timer4) { //씬4 진입 _ 칠득
		enterScene(scene4);
		
		CanWalk = false;
		SceneNow = scene4;
		SetBaseObj();
		lineS4 = true;
		line4 = CreateObject1(ScriptS4[0], SceneNow, 120, 455); //대사생성
		showObject(line4);

		stopTimer(timer4);
	}

	if (timer == enemyWalk) {

		if (battle) { //싸운다면?? _보스전 코딩

			imageNumE++; //이미지 넘버 1씩 증가
			int imageEN = (imageNumE % 2) + 1; //1~2까지 순차적으로.
			int imageEN3 = (imageNumE % 3); //0~2까지 순차적으로.

			if (Edirct >= enemyStartX) { //칠득이 초기좌표보다 목표점이 크면
				EnemyL = false; //왼쪽으로 가기 거짓
			}
			else {
				EnemyL = true;
			}

			if (!HitEnemy) { //공격중 아닐때
				if (!EnemyL && Ex < Edirct) { //오른쪽 방향 && 현좌표 목표보다 작으면
					Ex += dxE; //5픽셀씩 칠득이 좌표 증가
					setObjectImage(enemy, imageE_R[imageEN]); //이미지 변경하기(오른쪽)
					locateObject(enemy, SceneNow, Ex, 70); //칠득이 옮기기
				}
				else if (!EnemyL && Ex >= Edirct) { //오른쪽 방향인데 현좌표가 목표보다 같.커지면
					HitEnemy = true; //공격 ON
					
					if (SceneNow == scene5) IsitHit_P(); //피격 판정
					else IsitHit_P11();
					setTimer(HitEnemyt, 0.5f);
					startTimer(HitEnemyt); //공격시간 타이머 활성화
				}
				else if (EnemyL && Ex > Edirct) { //왼쪽 방향이고 현재좌표가 Ex보다 클 때
					Ex -= dxE; //5픽셀씩 칠득이 좌표 감소
					setObjectImage(enemy, imageE[imageEN]); //이미지 변경하기(왼쪽)
					locateObject(enemy, SceneNow, Ex, 70); //칠득이 옮기기
				}
				else if (EnemyL && Ex <= Edirct) { //왼쪽 방향인데 현좌표가 목표보다 같.작아지면
					HitEnemy = true; //공격
					if (SceneNow == scene5) IsitHit_P(); //피격 판정
					else IsitHit_P11();
					setTimer(HitEnemyt, 0.5f);
					startTimer(HitEnemyt); //공격시간 타이머 활성화
				}
			}
			else { //공격중이면
				if (!EnemyL) setObjectImage(enemy, imageE_FR[imageEN3]); //이미지 변경하기(오른쪽 공격)
				else setObjectImage(enemy, imageE_F[imageEN3]); //이미지 변경하기(왼쪽 공격)
			}

			setTimer(enemyWalk, 0.03f);
			startTimer(enemyWalk); //타이머 재시작

		}
		
		if (walkingE_come) { //칠득이 걸어오기.
			
			imageNumE++; //이미지 넘버 1씩 증가
			int imageEN = (imageNumE % 2)+1; //0~1까지 순차적으로.

			if (Ex > Edirct) { //디렉션 설정
				Ex -= dxE; //5픽셀씩 칠득이 좌표 감소
				setObjectImage(enemy, imageE[imageEN]); //이미지 변경하기

			}
			else if (Ex <= 600) { //600보다 작아진다면
				walkingE_come = false;
				stopTimer(enemyWalk); //칠득 타이머 종료

				hideObject(enemy), hideObject(prince); hideObject(inventory); //숨기기
				setSceneImage(scene4, "image/scene0.jpg");

				timer5 = createTimer(1.0f);
				startTimer(timer5);
			}
			else {
				setObjectImage(enemy, imageE[0]); //칠득이 정자세 돌려놓기
				imageNumE = 0;
				walkingE_come = false;
			}
			locateObject(enemy, scene4, Ex, 70); //위치 변경하기
			setTimer(enemyWalk, Espeed); //타이머 재설정.
			startTimer(enemyWalk); //타이머 바로 재시작.

		}
		
		if (walkingE_away) { //칠득이 빠지기
			
		}

	}

	if (timer == setTarget) { //왕자 좌표를 타겟으로 지정
		TargetX = x; //현재 왕자의 좌표를 타겟으로!
		
		setTimer(setTarget, 1.3f);
		startTimer(setTarget); //타이머 재시작
	}

	if (timer == HitEnemyt){ //칠득이 치는거 끝나면

		Edirct = TargetX; //변화된 타겟 좌표로 업데이트
		enemyStartX = Ex; //칠득이의 현재좌표를 시작점으로 업데이트함.

		HitEnemy = false; //때리기 종료!
		stopTimer(HitEnemyt); //타이머스탑
	}

	if (timer == HitPrincet) {

		stopTimer(HitPrincet);
		setTimer(timerp, ANIMATION_TIME);
		startTimer(timerp); 
	}

	if (timer == DPrincet) { //왕자 피격당할때
		setObjectImage(prince, imageP_L[0]); //끝나면 원래대로 돌려놓음

		setTimer(enemyWalk, 0.03f);
		startTimer(enemyWalk); //칠득 타이머 재시작

	}

	if (timer == timer5) { //씬 5로 넘어가는 타이머
		SceneNow = scene5; //씬 5를 현재 씬으로 설정
		enterScene(scene5); //보스전 돌입

		SetBaseObj(); //오브젝트 생성
		enemy = CreateObject1(imageE[0], SceneNow, 1000, 70); //칠득 배치
		showObject(enemy);
		locateObject(prince, SceneNow, 80, 70);
		hideObject(inventory); //인벤 감추기

		enemyBattle(); //배틀 시작
	}

	if (timer == timer6) {
		enterScene(scene7);
		lineS7 = true; //라인 true

		x = 100;
		line7 = CreateObject1(ScriptS7[0], SceneNow, 120, 455);
		SetBaseObj();
		showObject(line7);
	}

	if (timer == timer8) {
		enterScene(scene8);
		
		princess = CreateObject1("image/Ps1_L.png", SceneNow, 1000, 70);
		showObject(princess);
		x = 80;
		SetBaseObj();

		CanWalk = false; //걷기 비활성화
		invenOpen = true; //인벤 비활성화

		line8 = CreateObject1(ScriptS8[0], SceneNow, 120, 455);
		showObject(line8);
	}

	if (timer == timer9) {
		setObjectImage(line8, ScriptS8[10]);
		CanWalk = true;

		//lineS6 = false;
		//CanWalk = true;
		//lineNUM = 0; //넘버 초기화
		//hideObject(line6);
	}

	if (timer == timer10) {
		enterScene(scene9);
		invenOpen = false;
		CanWalk = true;

		x = 100;
		SetBaseObj();
	}

	if (timer == timerMixing) {
		game_random_move();

		if (mixing > 0) {
			--mixing;

			setTimer(timerMixing, animationTime);
			startTimer(timerMixing);
		}
		else {
			hideObject(startbutton);
			game = true;
		}
	}

	if (timer == timer12) {


		HitPrince = false;
		enterScene(scene11);
		SceneNow = scene11;
		enemy = CreateObject1(imageE[0], scene11, Ex, 70);
		showObject(enemy);

		SetBaseObj();//
		enemyBattle(); hideObject(inventory);
	}

	if (timer == timer13) {

		x = 700;
		SetBaseObj();
		enterScene(scene12);

		timer14 = createTimer(2.0f);
		startTimer(timer14); //타이머 즉시시작

	}

	if (timer == timer14) {
		line12 = CreateObject1(Script12[0], scene12, 120, 455);
		showObject(line12);

		lineNUM = 0;
	}

	if (timer == timer15) { //타이머 15번
		enterScene(scene13);//씬으로 들어가기

		line13 = CreateObject1(Script13[0], scene13, 120, 455);
		showObject(line13);

		lineNUM = 0;
	}

	if (timer == timer16) { //타이머 16번
		enterScene(scene14); //씬 14 진입

		line14 = CreateObject1(Script14[0], scene14, 120, 455);
		showObject(line14);

		lineNUM = 0;
	}
}


//마우스콜백
void mouseCallback(ObjectID obj, int x, int y, MouseAction action) {

	//퍼즐게임 전용
	if (game) {
		game_move(game_index(obj));

		if (game_check()) {
			game_end();
		}
	}
	else if (mixing == 0 && obj == startbutton) {
		game_prepare();
		//시간측정시작점
		time_start = time(NULL);
	}
	else if (obj == endbutton) {
		enterScene(scene10); //공주 잡힌 씬으로 진입.
		SceneNow = scene10;

		x = 100;
		SetBaseObj();
		CanWalk = false;
		lineS10 = true;
		lineNUM = 0; //초기화

		enemy = CreateObject1(imageE[0], SceneNow, 1000, 70);
		line10 = CreateObject1(ScriptS10[0], SceneNow, 120, 455);
		showObject(enemy), showObject(line10);
	}


	//대사
	if (obj == line) {

		if (lineS1) { //인트로 1 라인
			lineNUM++;
			if (lineNUM < 4) setObjectImage(line, ScriptS1[lineNUM]);
			else {
				lineS1 = false;
				lineNUM = 0; //넘버 초기화
				hideObject(line);

				lineS2 = true; //라인2 활성화
				line2 = CreateObject1(ScriptS2[0], scene2, 120, 455); //대사 생성
				showObject(line2);

				setSceneImage(scene1, "image/scene0.jpg");
				timer1 = createTimer(2.0f);
				startTimer(timer1);
			}
		}
	}
	
	if (obj == line2) { //인트로 2 라인
		if (lineS2) {
			lineNUM++;
			if (lineNUM < 11) {
				if (lineNUM == 4) {
					setObjectImage(prince, imageP_R[0]);
					setObjectImage(princess, "image/Ps1.png");
				}
				setObjectImage(line2, ScriptS2[lineNUM]);
			}
			else {
				lineS2 = false;
				lineNUM = 0; //넘버 초기화
				hideObject(line2);
				hideObject(prince); hideObject(princess); hideObject(KingE); hideObject(KingW); hideObject(Owner);

				setSceneImage(scene2, "image/scene0.jpg");
				timer2 = createTimer(2.0f);
				startTimer(timer2);

				SceneNow = scene3; //현재 씬을 3으로 설정.
				invenOpen = true; //인벤 비활성화
				lineS3 = true; //라인2 활성화
				line3 = CreateObject1(ScriptS3[0], scene3, 120, 455); //대사 생성
				showObject(line3);

			}
		}
	}
	
	if (obj == line3) { //스테이지 1 라인
		if (lineS3) {
			lineNUM++;
			if (lineNUM < 7) {
				if (lineNUM == 6) {
					hideObject(princess); //공주 숨기기
					timer3 = createTimer(2.0f);
					startTimer(timer3);
					setObjectImage(line3, "Inven_use.png"); //투명으로 잠시 교체
					lineS3 = false; //잠시 비활성화
				}
				else setObjectImage(line3, ScriptS3[lineNUM]);
			}
			else {
				hideObject(prince);
				SetBaseObj(); //기본 오브젝트 세팅

				invenOpen = false; //인벤 활성화
				lineS3 = false;
				lineNUM = 0; //넘버 초기화
				hideObject(line3);

			}
		}
	}

	if (obj == line4) {
		if (lineS4) {
			lineNUM++;
			if(lineNUM < 7){
				if (lineNUM == 1) {
					enemySet();
				}
				setObjectImage(line4, ScriptS4[lineNUM]);
			}
			else {
				lineS4 = false;
				lineNUM = 0; //넘버 초기화
				hideObject(line4);
				enemyRestart(); //칠득이 다시 달려오게
			}
		}
		
	}

	if (obj == line6) {
		if (lineS6) {
			lineNUM++;
			if (lineNUM < 4) {
				if (lineNUM == 1) {
					battle = false;
					walkingE_come = false;
					hideObject(enemy); //칠득 도망
				}
				setObjectImage(line6, ScriptS6[lineNUM]);
				setSceneImage(scene6, "image/scene4-2.png");
			}
			else {
				lineS6 = false;
				CanWalk = true;
				lineNUM = 0; //넘버 초기화
				hideObject(line6);
			}
		}
	}

	if (obj == line7) {
		if (lineS7) {
			lineNUM++;
			if (lineNUM < 2) {
				setObjectImage(line7, ScriptS7[1]);
			}
			else {
				setObjectImage(line7, "image/Inven_use.png");
			}
		}
	}
	
	if (obj == line8) {
		if (lineS8) {
			lineNUM++;
			if (lineNUM == 10) {
				setObjectImage(line8, "image/Inven_use.png");
				timer9 = createTimer(1.0f); //공주 타이머
				startTimer(timer9);
				hideObject(princess);
			}
			else if (lineNUM == 12) {
				lineS8 = false;
				hideObject(line8);
			}
			else {
				setObjectImage(line8, ScriptS8[lineNUM]);
			}
		}
	}
	
	if (obj == line10) {
		if (lineS10) {
			lineNUM++;
			if (lineNUM < 3) {
				setObjectImage(line10, ScriptS10[lineNUM]);
			}
			else {

				setSceneImage(scene10, "image/scene0.jpg");
				timer12 = createTimer(2.0f);
				startTimer(timer12);
				hideObject(prince); hideObject(line10); hideObject(enemy);
			}
		}
	}

	if (obj == line12) {
		lineNUM++;
		if (lineNUM < 38) {
			setObjectImage(line12, Script12[lineNUM]);
		}
		else {
			setSceneImage(scene12, "image/scene0.jpg");
			timer15 = createTimer(2.0f);
			startTimer(timer15);
			hideObject(prince); hideObject(line12); hideObject(enemy); hideObject(inventory);
		}
	}
	
	if (obj == line13) {
		lineNUM++;
		if (lineNUM < 8) {
			setObjectImage(line13, Script13[lineNUM]);
		}
		else {
			setSceneImage(scene13, "image/scene0.jpg");
			timer16 = createTimer(2.0f);
			startTimer(timer16);
			hideObject(line13);
		}
	}

	if (obj == line14) {
		lineNUM++;
		if (lineNUM == 4) {
			setSceneImage(scene14, "image/scene2-1.png"); //배경 변경
		}
		else if (lineNUM == 35) {
			endGame(); //게임 종료.
		}
		else {
			setObjectImage(line14, Script14[lineNUM]);
		}

	}



	if (obj == inventory) {
		if (!invenOpen) {
			showObject(invenWin);
			showObject(invenB_C);
			showObject(invenB_U);

			for (int i = 0; i < 10; i++) {
				showObject(invenItem[i]);
			}

			invenOpen = true;
		}
		else; //열려있지 않을 때만 열 수 있음.
	}

	if (obj == invenB_C) {
		hideObject(invenB_C);
		hideObject(invenB_U);
		hideObject(invenWin);

		for (int i = 0; i < 10; i++) {
			hideObject(invenItem[i]);
		}

		invenOpen = false;
	}

	if (obj == invenB_U) {
		if (Key7) {
			setSceneImage(scene7, "image/scene5-1.png");
			close7 = false;
		}
	}

}



int main() {
	
	//게임 옵션 설정
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

	black_win = CreateObject1("image/scene0.jpg", SceneNow, 0, 0);

	//인트로(#S1~2)
	scene1 = createScene("왕국배경", "image/scene1.jpg");
	line = CreateObject1(ScriptS1[0], scene1, 120, 455); //대사 생성
	showObject(line);
	lineS1 = true; //라인1 활성화

	scene2 = createScene("동굴입구", "image/scene2.png"); //씬2 장면
	prince = CreateObject1(imageP_L[0], scene2, 500, 70);
	princess = CreateObject1("image/Ps1_L.png", scene2, 600, 70);
	KingE = CreateObject1("image/K1.png", scene2, 100, 70);
	KingW = CreateObject1("image/KW_1.png", scene2, 200, 70);
	Owner = CreateObject1("image/Owner.png", scene2, 800, 70);
	showObject(prince); showObject(princess); showObject(KingE); showObject(KingW); showObject(Owner);
	
	//S#3
	scene3 = createScene("스테이지1", "image/scene3.png"); //씬3 생성
	scene4 = createScene("스테이지2_칠득", "image/scene4.png"); //씬4 생성
	scene5 = createScene("칠득 보스전", "image/scene4-1.png"); //씬5 생성
	scene6 = createScene("보스전 종료", "image/scene4.png"); //씬6 생성
	scene7 = createScene("열쇠찾기", "image/scene5.png");
	scene8 = createScene("대화", "image/scene6.png"); 
	scene9 = createScene("퍼즐게임", "image/scene6-1.png"); //씬9 생성
	scene10 = createScene("칠득 보스전 2차", "image/Example.png");
	scene11 = createScene("칠득 보스전 2차", "image/Example-1.png");
	scene12 = createScene("엔딩장소 전", "image/Example-2.png"); // 엔딩씬 전 장소
	scene13 = createScene("엔딩", "image/scene9.png"); //엔딩
	scene14 = createScene("엔딩_왕들", "image/scene2-2.png");

	////대사들

	setMouseCallback(mouseCallback);
	setTimerCallback(timerCallback);
	setKeyboardCallback(keyboardCallback);

	startGame(scene1);

	return 0;
}
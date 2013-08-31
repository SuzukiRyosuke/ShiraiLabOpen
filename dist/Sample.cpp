//http://sai-lab.net/blog/?p=129
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include "GL/glut.h"
#include "DistortionCorrection.h"

//�O���[�o���ϐ�
DistortionCorrection g_DC;
float g_cx = 0;
float g_cy = 0;
float g_kR = 0;
float g_kG = 0;
float g_kB = 0;

static void display(void)
{
	// ��ʃN���A
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//���f���r���[�ϊ��s��̐ݒ�
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//���邮����e�B�[�|�b�g�`��
	static float r = 0;
	glRotatef(r, 0.0, 1.0, 0.0);
	glutSolidTeapot(1);
	r += 1.0;

	//�c�ݕ␳���s
	g_DC.runDC();

	// �_�u���o�b�t�@�����O
	glutSwapBuffers();
}

static void reshape(int w, int h)
{
	//�E�B���h�E�S�̂��r���[�|�[�g�ɂ���
	glViewport(0, 0, w, h);
  
	//�����ϊ��s��̎w��
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (double)w / (double)h, 0.1, 100.0);
	gluLookAt(0.0, 2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//�c�ݕ␳�p�����[�^�ݒ�
	g_cx = w/2.0f;
	g_cy = h/2.0f;
	g_DC.setCenter(g_cx, g_cy);
}

static void idle(void)
{
	glutPostRedisplay();
}

static void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	
	// ESC�ŏI��
	case '\033':
		exit(0);
		break;

	//RGB���ꂼ��̘c�݌n���ݒ�
	case 'R':
		g_kR += 0.0001f;
		g_DC.setParams(g_kR, g_kG, g_kB);
		break;
	case 'r':
		g_kR -= 0.0001f;
		g_DC.setParams(g_kR, g_kG, g_kB);
		break;
	case 'G':
		g_kG += 0.0001f;
		g_DC.setParams(g_kR, g_kG, g_kB);
		break;
	case 'g':
		g_kG -= 0.0001f;
		g_DC.setParams(g_kR, g_kG, g_kB);
		break;
	case 'B':
		g_kB += 0.0001f;
		g_DC.setParams(g_kR, g_kG, g_kB);
		break;
	case 'b':
		g_kB -= 0.0001f;
		g_DC.setParams(g_kR, g_kG, g_kB);
		break;

	//�f�o�b�O�\���؂�ւ�
	case 'D':
	case 'd':
		g_DC.switchDebugMode();
		break;
	}
}

static void special(int key, int x, int y)
{
	switch(key){
	case GLUT_KEY_UP:
		g_cy += 1.0f;
		break;
	case GLUT_KEY_DOWN:
		g_cy -= 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		g_cx += 1.0f;
		break;
	case GLUT_KEY_LEFT:
		g_cx -= 1.0f;
		break;
	}

	//�c�݂̒��S��ݒ�
	g_DC.setCenter(g_cx, g_cy);
}

void initGL(int argc, char *argv[])
{
	glutInitWindowSize(800, 600);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("Distortion Correction Sample");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);

	glClearColor(0.0, 0.0, 0.0, 0.0); //�w�i�F���K�����ɂ��邱��
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

int main(int argc, char *argv[])
{
	//glut�̏�����
	initGL(argc, argv);
	
	//�c�ݕ␳�@�\������
	g_DC.init();

	glutMainLoop();
	return 0;
}
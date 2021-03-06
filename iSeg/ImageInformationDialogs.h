/*
 * Copyright (c) 2018 The Foundation for Research on Information Technologies in Society (IT'IS).
 * 
 * This file is part of iSEG
 * (see https://github.com/ITISFoundation/osparc-iseg).
 * 
 * This software is released under the MIT License.
 *  https://opensource.org/licenses/MIT
 */
#ifndef PIXELSIZE_28June05
#define PIXELSIZE_28June05

#include "Data/Vec3.h"

#include <q3hbox.h>
#include <q3vbox.h>
#include <qdialog.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qpainter.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qwidget.h>

namespace iseg {

class SlicesHandler;

class PixelResize : public QDialog
{
	Q_OBJECT
public:
	PixelResize(SlicesHandler* hand3D, QWidget* parent = 0,
				const char* name = 0, Qt::WindowFlags wFlags = 0);
	~PixelResize() {}
	Vec3 get_pixelsize();

private:
	SlicesHandler* handler3D;

	QLineEdit* le_dx;
	QLineEdit* le_dy;
	QLineEdit* le_dz;
	QLineEdit* le_lx;
	QLineEdit* le_ly;
	QLineEdit* le_lz;

	QPushButton* pb_resize;
	QPushButton* pb_close;

private slots:
	void dx_changed();
	void dy_changed();
	void dz_changed();
	void lx_changed();
	void ly_changed();
	void lz_changed();
	void resize_pressed();
};

class DisplacementDialog : public QDialog
{
	Q_OBJECT
public:
	DisplacementDialog(SlicesHandler* hand3D, QWidget* parent = 0,
					   const char* name = 0, Qt::WindowFlags wFlags = 0);
	~DisplacementDialog() {}
	void return_displacement(float disp[3]);

private:
	float displacement[3];
	SlicesHandler* handler3D;

	QLineEdit* le_dispx;
	QLineEdit* le_dispy;
	QLineEdit* le_dispz;
	QPushButton* pb_set;
	QPushButton* pb_close;

private slots:
	void dispx_changed();
	void dispy_changed();
	void dispz_changed();
	void set_pressed();
};

class RotationDialog : public QDialog
{
	Q_OBJECT
public:
	RotationDialog(SlicesHandler* hand3D, QWidget* parent = 0,
				   const char* name = 0, Qt::WindowFlags wFlags = 0);
	~RotationDialog();
	void get_rotation(float r[3][3]);

private:
	float rotation[3][3];
	SlicesHandler* handler3D;
	Q3HBox* hbox1;
	Q3HBox* hbox2;
	Q3HBox* hbox3;
	Q3VBox* vbox1;
	Q3VBox* vbox2;
	Q3VBox* vbox3;
	Q3VBox* vbox4;
	QLabel* lb_descr;
	QLabel* lb_c1;
	QLabel* lb_c2;
	QLabel* lb_c3;
	QLineEdit* le_r11;
	QLineEdit* le_r12;
	QLineEdit* le_r13;
	QLineEdit* le_r21;
	QLineEdit* le_r22;
	QLineEdit* le_r23;
	QLineEdit* le_r31;
	QLineEdit* le_r32;
	QLineEdit* le_r33;
	QPushButton* pb_orthonorm;
	QPushButton* pb_set;
	QPushButton* pb_close;

private slots:
	void rotation_changed();
	void set_pressed();
	void orthonorm_pressed();
};

class ImagePVLabel : public QLabel
{
	Q_OBJECT

public:
	ImagePVLabel(QWidget* parent = 0, Qt::WindowFlags f = 0);

	void SetWidth(int value) { m_Width = value; }
	void SetHeight(int value) { m_Height = value; }
	void SetScaledValue(float value) { m_Scale = value; }

public slots:
	void SetXMin(int value);
	void SetXMax(int value);
	void SetYMin(int value);
	void SetYMax(int value);

private slots:
	void paintEvent(QPaintEvent* e);

protected:
	int m_XMin;
	int m_XMax;
	int m_YMin;
	int m_YMax;

	int m_Width;
	int m_Height;

	float m_Scale;
};

class ResizeDialog : public QDialog
{
	Q_OBJECT
public:
	enum eResizeType { kOther = 0, kPad = 1, kCrop = 2 };

	ResizeDialog(SlicesHandler* hand3D, eResizeType type1 = kOther,
				 QWidget* parent = 0, const char* name = 0,
				 Qt::WindowFlags wFlags = 0);
	~ResizeDialog();
	void return_padding(int& dxm, int& dxp, int& dym, int& dyp, int& dzm,
						int& dzp);

private:
	int d[6];
	SlicesHandler* handler3D;
	Q3HBox* hbox1;
	Q3HBox* hbox2;
	Q3VBox* vbox1;
	Q3VBox* vbox2;
	Q3VBox* vbox3;
	Q3VBox* vbox4;
	Q3VBox* vbox5;
	QLabel* lb_dxm;
	QLabel* lb_dym;
	QLabel* lb_dzm;
	QLabel* lb_dxp;
	QLabel* lb_dyp;
	QLabel* lb_dzp;
	QSpinBox* sb_dxm;
	QSpinBox* sb_dym;
	QSpinBox* sb_dzm;
	QSpinBox* sb_dxp;
	QSpinBox* sb_dyp;
	QSpinBox* sb_dzp;
	QPushButton* pb_set;
	QPushButton* pb_close;
	Q3HBox* mainBox;
	Q3VBox* vImagebox1;
	ImagePVLabel* m_ImageSourceLabel;
	eResizeType resizetype;

private slots:
	void set_pressed();
};

} // namespace iseg

#endif

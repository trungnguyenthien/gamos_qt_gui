#include "BSimpleWindow.h"

BSimpleWindow::BSimpleWindow(QWidget *parent) : QTabWidget(parent) {
  phantomLayout = new QWidget(parent);
  sourceLayout = new QWidget(parent);
  outputLayout = new QWidget(parent);

  tabBar()->setDocumentMode(true);
  tabBar()->setExpanding(true);
  this->addTab(phantomLayout, "Phantom");
  this->addTab(sourceLayout, "Source");
  this->addTab(outputLayout, "Output");

  initPhantomLayout();
  initSourceLayout();
  initOutputLayout();
}

string BSimpleWindow::title() { return "SIMPLE MODE"; }

string BSimpleWindow::description() { return ""; }

QWidget *BSimpleWindow::self_widget() { return this; }

void BSimpleWindow::initPhantomLayout() {
  group_geom_source = {
      makeGroupNumberInputValue("BOX", "BOX",
                                {
                                    NumberInputValue("X_HALF_LENGTH", "X_HALF_LENGTH", "1", "mm"),
                                    NumberInputValue("Y_HALF_LENGTH", "Y_HALF_LENGTH", "1", "mm"),
                                    NumberInputValue("Z_HALF_LENGTH", "Z_HALF_LENGTH", "1", "mm"),
                                }),
      makeGroupNumberInputValue(
          "TUBE", "TUBE",
          {
              NumberInputValue("INNER_RADIUS", "INNER_RADIUS", "1", "mm"),
              NumberInputValue("OUTER_RADIUS", "OUTER_RADIUS", "1", "mm"),
              NumberInputValue("HALF_LENGTH_IN_Z", "HALF_LENGTH_IN_Z", "1", "mm"),
          }),
      makeGroupNumberInputValue(
          "TUBS", "TUBS",
          {
              NumberInputValue("INNER_RADIUS", "INNER_RADIUS", "1", "mm"),
              NumberInputValue("OUTER_RADIUS", "OUTER_RADIUS", "1", "mm"),
              NumberInputValue("HALF_LENGTH_IN_Z", "HALF_LENGTH_IN_Z", "1", "mm"),
              NumberInputValue("STARTING_PHI_ANGLE", "STARTING_PHI_ANGLE", "1", "°"),
              NumberInputValue("DELTA_PHI_ANGLE_OF_SEGMENT", "DELTA_PHI_ANGLE_OF_SEGMENT", "1",
                               "°"),
          }),
      makeGroupNumberInputValue(
          "CONE", "CONE",
          {
              NumberInputValue("INNER_RADIUS-FDZ", "INNER_RADIUS-FDZ", "1", "mm"),
              NumberInputValue("OUTER_RADIUS-FDZ", "OUTER_RADIUS-FDZ", "1", "mm"),
              NumberInputValue("INNER_RADIUS+FDZ", "INNER_RADIUS+FDZ", "1", "mm"),
              NumberInputValue("OUTER_RADIUS+FDZ", "OUTER_RADIUS+FDZ", "1", "mm"),
              NumberInputValue("HALF_LENGTH_IN_Z", "HALF_LENGTH_IN_Z", "1", "mm"),
          }),
      makeGroupNumberInputValue(
          "CONS", "CONS",
          {
              NumberInputValue("INNER_RADIUS-FDZ", "INNER_RADIUS-FDZ", "1", "mm"),
              NumberInputValue("OUTER_RADIUS-FDZ", "OUTER_RADIUS-FDZ", "1", "mm"),
              NumberInputValue("INNER_RADIUS+FDZ", "INNER_RADIUS+FDZ", "1", "mm"),
              NumberInputValue("OUTER_RADIUS+FDZ", "OUTER_RADIUS+FDZ", "1", "mm"),
              NumberInputValue("HALF_LENGTH_IN_Z", "HALF_LENGTH_IN_Z", "1", "mm"),
              NumberInputValue("STARTING_PHI_ANGLE", "STARTING_PHI_ANGLE", "1", "°"),
              NumberInputValue("DELTA_PHI_ANGLE_OF_SEGMENT", "DELTA_PHI_ANGLE_OF_SEGMENT", "1",
                               "°"),
          }),
      makeGroupNumberInputValue(
          "CONE", "CONE",
          {
              NumberInputValue("INNER_RADIUS-FDZ", "INNER_RADIUS-FDZ", "1", "mm"),
              NumberInputValue("OUTER_RADIUS-FDZ", "OUTER_RADIUS-FDZ", "1", "mm"),
              NumberInputValue("INNER_RADIUS+FDZ", "INNER_RADIUS+FDZ", "1", "mm"),
              NumberInputValue("OUTER_RADIUS+FDZ", "OUTER_RADIUS+FDZ", "1", "mm"),
              NumberInputValue("HALF_LENGTH_IN_Z", "HALF_LENGTH_IN_Z", "1", "mm"),
          }),
      makeGroupNumberInputValue(
          "TRD", "TRD",
          {
              NumberInputValue("HAFT_LENGTH_ALONG_X_AT_THE_SURFACE_POSITIONED_AT-DZ",
                               "HAFT_LENGTH_ALONG_X_AT_THE_SURFACE_POSITIONED_AT-DZ", "1", "mm"),
              NumberInputValue("HAFT_LENGTH_ALONG_X_AT_THE_SURFACE_POSITIONED_AT+DZ",
                               "HAFT_LENGTH_ALONG_X_AT_THE_SURFACE_POSITIONED_AT+DZ", "1", "mm"),
              NumberInputValue("HAFT_LENGTH_ALONG_Y_AT_THE_SURFACE_POSITIONED_AT-DZ",
                               "HAFT_LENGTH_ALONG_Y_AT_THE_SURFACE_POSITIONED_AT-DZ", "1", "mm"),
              NumberInputValue("HAFT_LENGTH_ALONG_Y_AT_THE_SURFACE_POSITIONED_AT+DZ",
                               "HAFT_LENGTH_ALONG_Y_AT_THE_SURFACE_POSITIONED_AT+DZ", "1", "mm"),
              NumberInputValue("HALF_LENGTH_ALONG_Z_AXIS", "HALF_LENGTH_ALONG_Z_AXIS", "1", "mm"),
          }),
      makeGroupNumberInputValue(
          "SPHERE", "SPHERE",
          {
              NumberInputValue("INNER_RADIUS", "INNER_RADIUS", "1", "mm"),
              NumberInputValue("OUTER_RADIUS", "OUTER_RADIUS", "1", "mm"),
              NumberInputValue("STARTING_PHI_ANGLE", "STARTING_PHI_ANGLE", "1", "°"),
              NumberInputValue("DELTA_PHI_ANGLE_OF_SEGMENT", "DELTA_PHI_ANGLE_OF_SEGMENT", "1",
                               "°"),
              NumberInputValue("STARTING_THETA_ANGLE", "STARTING_THETA_ANGLE", "1", "°"),
              NumberInputValue("DELTA_THETA_ANGLE_OF_SEGMENT", "DELTA_THETA_ANGLE_OF_SEGMENT", "1",
                               "°"),
          }),
      makeGroupNumberInputValue("ORB", "ORB",
                                {
                                    NumberInputValue("OUTER_RADIUS", "OUTER_RADIUS", "1", "mm"),
                                }),
      makeGroupNumberInputValue(
          "TORUS", "TORUS",
          {
              NumberInputValue("INNER_RADIUS", "INNER_RADIUS", "1", "mm"),
              NumberInputValue("OUTER_RADIUS", "OUTER_RADIUS", "1", "mm"),
              NumberInputValue("SWEPT_RADIUS_OF_TORUS", "SWEPT_RADIUS_OF_TORUS", "1", "°"),
              NumberInputValue("STARTING_PHI_ANGLE", "STARTING_PHI_ANGLE", "1", "°"),
              NumberInputValue("DELTA_PHI_ANGLE_OF_SEGMENT", "DELTA_PHI_ANGLE_OF_SEGMENT", "1",
                               "°"),
          }),

  };
}

void BSimpleWindow::initSourceLayout() {}

void BSimpleWindow::initOutputLayout() {}

import os

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

from PyQt6.QtWidgets import QApplication

from dft_agent_flow.gui import DftAgentWindow


def test_goal_tabs_offer_structured_course_and_atpg_objectives() -> None:
    app = QApplication.instance() or QApplication([])
    window = DftAgentWindow()

    assert window.goal_tabs.count() == 4
    assert window.lab_table.rowCount() == 9
    course_index = window.dftc_mode.findData("course")
    assert course_index >= 0
    window.dftc_mode.setCurrentIndex(course_index)
    assert "完整 DFTC 课程" in window.dftc_goal_editor.toPlainText()
    assert window.run_action.isEnabled()

    window.goal_tabs.setCurrentIndex(1)
    window.fan_coverage.setValue(97.5)
    assert "97.50%" in window.fan_goal_editor.toPlainText()
    window.goal_tabs.setCurrentIndex(2)
    assert "secworks_aes" in window.external_goal_editor.toPlainText()
    window.close()
    app.processEvents()

from dft_agent_flow.runner import AtpgMetrics, FanRunner, FlowValidationError, Goal, parse_report


REPORT = """#    test coverage                            94.55%
#    fault coverage                           94.55%
#  #Patterns                                       5
#  ATPG runtime                            6.5e-05 s
"""


def test_parse_report() -> None:
    metrics = parse_report(REPORT, "s27", "static_dynamic")
    assert metrics.fault_coverage == 94.55
    assert metrics.patterns == 5
    assert metrics.runtime_seconds == 6.5e-05


def test_goal_prefers_fewer_patterns_after_satisfaction() -> None:
    goal = Goal(min_coverage=94.5, max_patterns=8)
    compact = AtpgMetrics("s27", "static_dynamic", 94.55, 94.55, 5, 0.01)
    longer = AtpgMetrics("s27", "static", 94.55, 94.55, 9, 0.01)
    assert FanRunner._ranking_key(compact, goal) < FanRunner._ranking_key(longer, goal)


def test_invalid_goal_is_rejected() -> None:
    try:
        Goal(min_coverage=120.0).validate()
    except FlowValidationError:
        return
    raise AssertionError("invalid coverage should fail validation")

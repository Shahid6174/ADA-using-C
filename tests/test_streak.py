import pytest
from streak import longest_positive_streak

def test_empty_list():
    """Test that an empty list returns a streak of 0."""
    assert longest_positive_streak([]) == 0

def test_no_positive_numbers():
    """Test that a list with no positive numbers returns a streak of 0."""
    assert longest_positive_streak([-1, -2, 0, -5]) == 0

def test_single_streak():
    """Test a simple case with a single streak of positive numbers."""
    assert longest_positive_streak([1, 2, 3, 4, 5]) == 5

def test_multiple_streaks_longest_last():
    """Test multiple streaks where the longest streak is at the end."""
    assert longest_positive_streak([1, 2, 0, 1, 2, 3]) == 3

def test_multiple_streaks_longest_first():
    """Test multiple streaks where the longest streak is at the beginning."""
    assert longest_positive_streak([1, 2, 3, 0, 1, 2]) == 3

def test_streaks_with_negatives():
    """Test streaks separated by negative numbers."""
    assert longest_positive_streak([1, 2, -1, 1, 2, 3, -5, 1]) == 3

def test_streaks_with_zeros():
    """Test streaks separated by zeros."""
    assert longest_positive_streak([1, 0, 2, 3, 0, 4, 5, 6]) == 3

def test_all_zeros_and_negatives():
    """Test a list containing only zeros and negative numbers."""
    assert longest_positive_streak([0, -1, 0, -2, -3]) == 0

def test_single_element_positive():
    """Test a list with a single positive number."""
    assert longest_positive_streak([5]) == 1

def test_single_element_non_positive():
    """Test a list with a single non-positive number."""
    assert longest_positive_streak([-5]) == 0
    assert longest_positive_streak([0]) == 0
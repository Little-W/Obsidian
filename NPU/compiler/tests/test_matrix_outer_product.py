from __future__ import annotations

import sys
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

import matrix_outer_product as schedule


class MatrixOuterProductScheduleTests(unittest.TestCase):
    def test_grouped_order_reuses_a_and_b_blocks(self) -> None:
        plan = schedule.build_matrix_schedule(
            96,
            80,
            96,
            block_m=32,
            block_n=40,
            block_k=32,
            row_group_blocks=2,
            column_group_blocks=2,
            mt=8,
            nt=8,
            kt=16,
        )
        self.assertEqual(len(plan.row_blocks), 3)
        self.assertEqual(len(plan.column_blocks), 2)
        self.assertEqual(len(plan.reduction_blocks), 3)
        self.assertEqual(len(plan.groups), 2)
        self.assertEqual(plan.groups[0].output_block_count, 4)
        first_reduction = plan.groups[0].reductions[0]
        self.assertEqual(
            [
                (
                    item.row.index,
                    item.column.index,
                    item.reduction.index,
                )
                for item in first_reduction.products
            ],
            [
                (0, 0, 0),
                (1, 0, 0),
                (0, 1, 0),
                (1, 1, 0),
            ],
        )
        self.assertTrue(
            all(item.a_use_count == 2 for item in first_reduction.products)
        )
        self.assertTrue(
            all(item.b_use_count == 2 for item in first_reduction.products)
        )
        self.assertEqual(plan.product_count, 18)

    def test_tail_blocks_preserve_exact_matrix_extents(self) -> None:
        plan = schedule.build_matrix_schedule(
            65,
            70,
            67,
            block_m=64,
            block_n=64,
            block_k=64,
            mt=8,
            nt=8,
            kt=16,
        )
        self.assertEqual(
            [(item.start, item.size) for item in plan.row_blocks],
            [(0, 64), (64, 1)],
        )
        self.assertEqual(
            [(item.start, item.size) for item in plan.column_blocks],
            [(0, 64), (64, 6)],
        )
        self.assertEqual(
            [(item.start, item.size) for item in plan.reduction_blocks],
            [(0, 64), (64, 3)],
        )
        self.assertEqual(plan.product_count, 8)

    def test_products_cover_the_same_sum_as_a_direct_matrix_product(
        self,
    ) -> None:
        m, n, k = 9, 10, 17
        left = [
            [((row * 5 + column * 3) % 11) - 5 for column in range(k)]
            for row in range(m)
        ]
        right = [
            [
                ((row * 7 + column * 2) % 13) - 6
                for column in range(n)
            ]
            for row in range(k)
        ]
        expected = [
            [
                sum(
                    left[row][reduction] * right[reduction][column]
                    for reduction in range(k)
                )
                for column in range(n)
            ]
            for row in range(m)
        ]
        actual = [[0 for _column in range(n)] for _row in range(m)]
        plan = schedule.build_matrix_schedule(
            m,
            n,
            k,
            block_m=8,
            block_n=8,
            block_k=16,
            row_group_blocks=2,
            column_group_blocks=2,
            mt=8,
            nt=8,
            kt=16,
        )
        for product in plan.products():
            for row in range(product.row.start, product.row.stop):
                for column in range(
                    product.column.start, product.column.stop
                ):
                    actual[row][column] += sum(
                        left[row][reduction] * right[reduction][column]
                        for reduction in range(
                            product.reduction.start,
                            product.reduction.stop,
                        )
                    )
        self.assertEqual(actual, expected)

    def test_invalid_block_size_is_rejected(self) -> None:
        with self.assertRaisesRegex(
            schedule.MatrixScheduleError, "at most 64"
        ):
            schedule.build_matrix_schedule(
                8, 8, 8, block_m=65
            )
        with self.assertRaisesRegex(
            schedule.MatrixScheduleError, "divisible"
        ):
            schedule.build_matrix_schedule(
                8, 8, 8, block_n=6, nt=4
            )


if __name__ == "__main__":
    unittest.main()

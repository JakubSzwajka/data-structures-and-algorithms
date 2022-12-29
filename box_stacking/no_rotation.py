from typing import List


class Box:
    def __init__(self, l, w, h) -> None:
        self.l = l
        self.w = w
        self.h = h

        self.box_under = None

    @property
    def total_height(self):
        if self.box_under is not None:
            return self.box_under.total_height + self.h
        else:
            return self.h

    def __eq__(self, other) -> bool:
        return self.l == other.l and self.w == other.w and self.h == other.h


def get_tallest_stack(boxes: List[Box]):
    for i in range(len(boxes))[:6]:
        box = boxes[i]
        box_under = max(
            [b for b in boxes if b.w > box.w and b.l > box.l and b != box],
            key=lambda x: x.total_height,
            default=None,
        )
        boxes[i].box_under = box_under

    tallest_stack = max(
        [b for b in boxes if b.box_under is not None], key=lambda b: b.total_height
    )
    return tallest_stack.total_height


def test_box_stacking():
    boxes = [
        Box(b[0], b[1], b[2])
        for b in [(4, 5, 3), (2, 3, 2), (3, 6, 2), (1, 5, 4), (2, 4, 1), (1, 2, 2)]
    ]
    assert get_tallest_stack(boxes) == 7

    boxes = [
        Box(b[0], b[1], b[2])
        for b in [
            (3, 4, 5),
            (4, 4, 4),
            (5, 5, 3),
            (3, 2, 2),
            (2, 1, 1),
        ]
    ]

    assert get_tallest_stack(boxes) == 10

    boxes = [
        Box(b[0], b[1], b[2])
        for b in [
            (5, 4, 3),
            (6, 5, 4),
            (4, 3, 5),
            (3, 2, 2),
            (2, 3, 1),
        ]
    ]
    assert get_tallest_stack(boxes) == 14


expected_output = 10

if __name__ == "__main__":
    test_box_stacking()

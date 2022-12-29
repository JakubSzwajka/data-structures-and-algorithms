from typing import List
import itertools
import pytest 

class Box:
    def __init__(self, l, w, h) -> None:
        self.rotations = self.get_rotations(l, w, h)

    def get_rotations(self, l, w, h):
        return [Rotation(r[0], r[1], r[2], self) for r in itertools.permutations((l, w,h), 3)]

class Rotation(Box):
    def __init__(self, l, w, h, box) -> None:
        self.l = l
        self.w = w
        self.h = h
        self.box = box
        self.box_under = None
    
    @property
    def total_height(self):
        if self.box_under is not None:
            return self.box_under.total_height + self.h
        else:
            return self.h
        
    def __eq__(self, other) -> bool:
        return self.l == other.l and self.w == other.w and self.h == other.h 

    def __repr__(self) -> str:
        return f"{self.l} x {self.w} x {self.h} -> {self.box_under}"
        
    def can_be_stacked_on_top_of(self, other) -> bool:
        return self.w < other.w and self.l < other.l and self != other and self.box != other.box


def get_tallest_stack(boxes: List[Box]):
    rotations = []
    for b in boxes:
        rotations += b.rotations 
    
    for i in range(len(rotations)):
        box = rotations[i]
        box_under = max(
            [b for b in rotations if b.can_be_stacked_on_top_of(box)],
            key=lambda x: x.total_height,
            default=None,
        )
        rotations[i].box_under = box_under

    tallest_stack = max(
        [b for b in rotations], key=lambda b: b.total_height
    )
    return tallest_stack.total_height

@pytest.mark.parametrize(
    "boxes_dimentions, highest_stack",
    [
        ([(4,6,7)], 7),
        ([(4,6,7), (12,10,7), (2,1,3)], 22),
        ([(4,6,7), (12,10,7), (2,1,3), (1,1,3)], 22),
        ([(4,6,7), (12,10,7), (2,1,3), (1,1,3), (2,1,13)], 32),
        ([(4,6,7), (12,10,7), (2,1,3), (1,1,3), (2,1,13), (3,20,50)], 64),
    ]
)
def test_box_stacking(boxes_dimentions, highest_stack):    
    boxes = [
        Box(b[0], b[1], b[2])
        for b in boxes_dimentions
    ]
    assert get_tallest_stack(boxes) == highest_stack

#include "EnemyBase.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"
#include "../Food/Food.h"

#define D_ENEMY_SPEED	(50.0f)

EnemyBase::EnemyBase() :
	move_animation(),
	dying_animation(),
	velocity(0.0f),
	enemybase_state(eEnemyBaseState::MOVEE),
	now_direction_state(eDirectionState::LEFT),
	next_direction_state(eDirectionState::LEFT),
	food_count(0),
	animation_time(0.0f),
	animation_count(0),
	old_panel(ePanelID::NONE),
	is_power_up(false),
	is_destroy(false)
{

}

EnemyBase::~EnemyBase()
{

}

void EnemyBase::Initialize()
{
	// �A�j���[�V�����摜�̓ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	move_animation = rm->GetImages("Resource/Images/monster.png", 12, 12, 1, 32, 32);
	dying_animation = rm->GetImages("Resource/Images/dying.png", 11, 11, 1, 32, 32);

	// �����蔻��̐ݒ�
	collision.is_blocking = true;
	collision.object_type = eObjectType::player;
	collision.hit_object_type.push_back(eObjectType::enemy);
	collision.hit_object_type.push_back(eObjectType::wall);
	collision.hit_object_type.push_back(eObjectType::food);
	collision.hit_object_type.push_back(eObjectType::power_food);
	collision.hit_object_type.push_back(eObjectType::special);
	collision.radius = (D_OBJECT_SIZE - 1.0f) / 2.0f;

	// ���C���[�̐ݒ�
	z_layer = 5;

	// �����̐ݒ�
	mobility = eMobilityType::Movable;
}

void EnemyBase::Update(float delta_second)
{
	// �v���C���[��Ԃɂ���āA�����ς���
	switch (enemybase_state)
	{
	case eEnemyBaseState::IDLEE:
		// �摜�̐ݒ�
		image = move_animation[9];
		break;
	case eEnemyBaseState::MOVEE:
		// �ړ�����
		Movement(delta_second);
		// �A�j���[�V��������
		AnimationControl(delta_second);
		break;
	case eEnemyBaseState::DIEE:
		// ���S���̃A�j���[�V����
		animation_time += delta_second;
		if (animation_time >= 0.07f)
		{
			animation_time = 0.0f;
			animation_count++;
			// ����������
			if (animation_count >= dying_animation.size())
			{
				enemybase_state = eEnemyBaseState::IDLEE;
				animation_count = 0;
				is_destroy = true;
			}
		}
		image = dying_animation[animation_count];
		break;
	default:
		break;
	}
}

void EnemyBase::Draw(const Vector2D& screen_offset) const
{
	// �e�N���X�̕`�揈�����Ăяo��
	__super::Draw(screen_offset);
}

void EnemyBase::Finalize()
{
	// ���I�z��̉��
	move_animation.clear();
	dying_animation.clear();
}

/// <summary>
/// �����蔻��ʒm����
/// </summary>
/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
void EnemyBase::OnHitCollision(GameObjectBase* hit_object)
{
	// ���������A�I�u�W�F�N�g���ǂ�������
	if (hit_object->GetCollision().object_type == eObjectType::wall)
	{
		// �����蔻������擾���āA�J�v�Z��������ʒu�����߂�
		CapsuleCollision hc = hit_object->GetCollision();
		hc.point[0] += hit_object->GetLocation();
		hc.point[1] += hit_object->GetLocation();

		// �ŋߖT�_�����߂�
		Vector2D near_point = NearPointCheck(hc, this->location);

		// Player����near_point�ւ̕����x�N�g�����擾
		Vector2D dv2 = near_point - this->location;
		Vector2D dv = this->location - near_point;

		// �߂荞�񂾍���
		float diff = (this->GetCollision().radius + hc.radius) - dv.Length();

		// diff�̕������߂�
		location += dv.Normalize() * diff;
	}

	// ���������A�I�u�W�F�N�g���ʏ�a��������
	if (hit_object->GetCollision().object_type == eObjectType::food)
	{
		food_count++;
	}

	// ���������A�I�u�W�F�N�g���p���[�a��������
	if (hit_object->GetCollision().object_type == eObjectType::power_food)
	{
		food_count++;
		is_power_up = true;
	}

	// ���������I�u�W�F�N�g���G��������
	if (hit_object->GetCollision().object_type == eObjectType::enemy)
	{
		enemybase_state = eEnemyBaseState::DIEE;
	}
}

/// <summary>
/// �a��H�ׂ����擾
/// </summary>
/// <returns>�a��H�ׂ���</returns>
int EnemyBase::GetFoodCount() const
{
	return food_count;
}

/// <summary>
/// �v���C���[�̏�Ԃ��擾����
/// </summary>
/// <returns>�v���C���[�̏��</returns>
eEnemyBaseState EnemyBase::GetEnemyBaseState() const
{
	return enemybase_state;
}

/// <summary>
/// �v���C���[���p���[�A�b�v���Ă邩�m�F����
/// </summary>
/// <returns>�v���C���[�̏��</returns>
bool EnemyBase::GetPowerUp() const
{
	return is_power_up;
}

/// <summary>
/// �p���[�_�E��������
/// </summary>
void EnemyBase::SetPowerDown()
{
	is_power_up = false;
}

bool EnemyBase::GetDestroy() const
{
	return is_destroy;
}

/// <summary>
/// �ړ�����
/// </summary>
/// <param name="delta_second">1�t���[��������̎���</param>
void EnemyBase::Movement(float delta_second)
{
	// �ړ��ʂ���ړ��������X�V
	if (Vector2D::Distance(old_location, location) == 0.0f)
	{
		// �ړ����Ȃ���� direction_state ��ύX����
		velocity = 0.0f;
		now_direction_state = next_direction_state;
		next_direction_state = eDirectionState::NONE;
	}
	else
	{
		// �ړ������Ɉړ����Ă��Ȃ���� direction_state ��ύX����
		switch (now_direction_state)
		{
		case eDirectionState::UP:
		case eDirectionState::DOWN:
		{
			float diff = location.y - old_location.y;
			if (((now_direction_state == eDirectionState::UP) && (diff < 0.0f)) ||
				((now_direction_state == eDirectionState::DOWN) && (0.0f < diff)))
			{
				// �ړ������Ɉړ����Ă�̂� break
				break;
			}

			velocity.y = 0.0f;
			now_direction_state = next_direction_state;
			next_direction_state = eDirectionState::NONE;
		}
		break;

		case eDirectionState::LEFT:
		case eDirectionState::RIGHT:
		{

			float diff = location.x - old_location.x;
			if (((now_direction_state == eDirectionState::LEFT) && (diff < 0.0f)) ||
				((now_direction_state == eDirectionState::RIGHT) && (0.0f < diff)))
			{
				// �ړ������Ɉړ����Ă�̂� break
				break;
			}

			velocity.x = 0.0f;
			now_direction_state = next_direction_state;
			next_direction_state = eDirectionState::NONE;
		}
		break;

		default:// �������Ȃ�
			break;
		}
	}

	// ���͏�Ԃ̎擾
	InputManager* input = InputManager::GetInstance();

	// ���݃p�l���̏�Ԃ��m�F
	ePanelID panel = StageData::GetPanelData(location);

	// ���͂���ړ�������ݒ�
	if (input->GetKeyDown(KEY_INPUT_UP) || input->GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		switch (now_direction_state)
		{
		case eDirectionState::UP:
			old_panel = ePanelID::NONE;
		case eDirectionState::DOWN:
		case eDirectionState::NONE:
			now_direction_state = eDirectionState::UP;
			break;

		default:
			next_direction_state = eDirectionState::UP;
		}
	}
	else if (input->GetKeyDown(KEY_INPUT_DOWN) || input->GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		switch (now_direction_state)
		{
		case eDirectionState::DOWN:
			old_panel = ePanelID::NONE;
		case eDirectionState::UP:
		case eDirectionState::NONE:
			now_direction_state = eDirectionState::DOWN;
			break;

		default:
			next_direction_state = eDirectionState::DOWN;
		}
	}
	else if (input->GetKeyDown(KEY_INPUT_LEFT) || input->GetButtonDown(XINPUT_BUTTON_DPAD_LEFT))
	{
		switch (now_direction_state)
		{
		case eDirectionState::LEFT:
			old_panel = ePanelID::NONE;
		case eDirectionState::RIGHT:
		case eDirectionState::NONE:
			now_direction_state = eDirectionState::LEFT;
			break;

		default:
			next_direction_state = eDirectionState::LEFT;
		}
	}
	else if (input->GetKeyDown(KEY_INPUT_RIGHT) || input->GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT))
	{
		switch (now_direction_state)
		{
		case eDirectionState::RIGHT:
			old_panel = ePanelID::NONE;
		case eDirectionState::LEFT:
		case eDirectionState::NONE:
			now_direction_state = eDirectionState::RIGHT;
			break;

		default:
			next_direction_state = eDirectionState::RIGHT;
		}
	}

	// �i�s�����̈ړ��ʂ�ǉ�
	switch (now_direction_state)
	{
	case EnemyBase::UP:
		velocity.y = -1.0f;
		break;
	case EnemyBase::DOWN:
		velocity.y = 1.0f;
		break;
	case EnemyBase::LEFT:
		velocity.x = -1.0f;
		break;
	case EnemyBase::RIGHT:
		velocity.x = 1.0f;
		break;
	default:
		velocity = 0.0f;
		now_direction_state = next_direction_state;
		next_direction_state = EnemyBase::NONE;
		break;
	}

	// ��s���͂̈ړ��ʂ�ǉ�
	if ((panel != ePanelID::NONE)
		&& (old_panel != panel))
	{
		switch (next_direction_state)
		{
		case EnemyBase::UP:
			velocity.y = -1.0f;
			break;
		case EnemyBase::RIGHT:
			velocity.x = 1.0f;
			break;
		case EnemyBase::DOWN:
			velocity.y = 1.0f;
			break;
		case EnemyBase::LEFT:
			velocity.x = -1.0f;
			break;
		default:
			break;
		}
	}

	// �O����W�̍X�V
	old_location = location;

	// �O��p�l���̍X�V
	old_panel = panel;

	// �ړ��� * ���� * ���� �ňړ�������肷��
	location += velocity * D_ENEMY_SPEED * delta_second;

	// ��ʊO�ɍs������A���Α��Ƀ��[�v������
	if (location.x < 0.0f)
	{
		old_location.x = 672.0f;
		location.x = 672.0f - collision.radius;
		velocity.y = 0.0f;
	}
	if (672.0f < location.x)
	{
		old_location.x = 0.0f;
		location.x = collision.radius;
		velocity.y = 0.0f;
	}
}

/// <summary>
/// �A�j���[�V��������
/// </summary>
/// <param name="delta_second">1�t���[��������̎���</param>
void EnemyBase::AnimationControl(float delta_second)
{
	// �ړ����̃A�j���[�V����
	animation_time += delta_second;
	if (animation_time >= (1.0f / 16.0f))
	{
		animation_time = 0.0f;
		animation_count++;
		if (animation_count >= 4)
		{
			animation_count = 0;
		}
		// �摜�̐ݒ�
		int dir_num = (int)now_direction_state;
		if (0 <= dir_num && dir_num < 4)
		{
			image = move_animation[(dir_num * 3) + animation_num[animation_count]];
		}

	}
}

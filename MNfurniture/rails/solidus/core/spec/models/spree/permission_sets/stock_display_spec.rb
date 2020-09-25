# frozen_string_literal: true

require 'rails_helper'

RSpec.describe Spree::PermissionSets::StockDisplay do
  let(:ability) { DummyAbility.new }

  subject { ability }

  context "when activated" do
    before do
      described_class.new(ability).activate!
    end

    it { is_expected.to be_able_to(:read, Spree::StockItem) }
    it { is_expected.to be_able_to(:admin, Spree::StockItem) }
    it { is_expected.to be_able_to(:read, Spree::StockLocation) }
  end

  context "when not activated" do
    it { is_expected.not_to be_able_to(:read, Spree::StockItem) }
    it { is_expected.not_to be_able_to(:admin, Spree::StockItem) }
    it { is_expected.not_to be_able_to(:read, Spree::StockLocation) }
  end
end
